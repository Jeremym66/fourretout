#include "daemon.h"

int main() 
{
    pthread_t fileMonitorThread;


    startDaemon();

    if (pthread_create(&fileMonitorThread, NULL, monitorFile, NULL) != 0) 
    {
        perror("Failed to create file monitor thread");
        return 1;
    }
    NetworkRequests();

    pthread_join(fileMonitorThread, NULL);
    cleanup();
    return 0;
}

void handlerSignal2(int sig)
{
    printf("test\n");
}

void startDaemon() 
{
    signal(SIGTERM, &handleSignal);
    signal(SIGHUP, &handleSignal);
    signal(40, &handlerSignal2);
    pid_t pid = fork();

    if (pid < 0)
        exit(EXIT_FAILURE);

    if (pid > 0)
        exit(EXIT_SUCCESS);

    setsid();

    // struct sigaction sa;
    
    // sa.sa_handler = handleSignal;
    // sigemptyset(&sa.sa_mask);
    // sa.sa_flags = 0;

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}



void handleSignal(int sig) 
{
    shutdownRequested = 1;
}

void *monitorFile(void *arg) 
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;

    while (!shutdownRequested) 
    {
        file = fopen(PATH, "r");
        if (file) 
        {
            while (getline(&line, &len, file) != -1)
                addEntry(line);
            fclose(file);
            printf("line ajoutee : %s\n", line);
        }
        free(line);
        line = NULL;
        sleep(1);
    }
    return NULL;
}

void NetworkRequests()  // Code pour mettre en place le serveur TCP sur le port 4848
{
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0); // Créer le socket
    if (serverSocket < 0) 
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    memset(&serverAddr, 0, sizeof(serverAddr)); // Initialiser la structure sockaddr_in
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(PORT);

    // Lier le socket à l'adresse et au port spécifiés
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("Socket bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(serverSocket, 5) < 0) // Mettre en écoute sur le port spécifié
    {
        perror("Socket listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Daemon en attente de connexions sur le port 4848...\n");


    while (!shutdownRequested) 
    {
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if (clientSocket < 0) 
        {
            if (errno == EINTR) continue;
            perror("Socket accept failed");
            break;
        }

        char buffer[1024];
        memset(buffer, 0, 1024);

        ssize_t readSize = read(clientSocket, buffer, 1023);
        if (readSize > 0) {
            processCommand(clientSocket, buffer);
        } else {
            perror("Socket read failed");
        }

        close(clientSocket);
    }

    stopServer();
}

    // Code pour traiter les commandes reçues du réseau
void processCommand(int clientSocket, char *command) 
{
    char response[1024];

    if (strncmp(command, "@@", 2) == 0) 
        listEntries(clientSocket); // Lister toutes les entrées sans les supprimer
    else if (command[0] == '#')
    {
        int order = atoi(command + 1);
        Entry *entry = findEntryByOrder(order);
        if (entry)
        {
            snprintf(response, sizeof(response), "> Number: %d\n> String: %s\n> Date: %ld\n",
                     entry->order, entry->string, entry->timestamp);
            write(clientSocket, response, strlen(response));
            deleteEntry(order); // Supprimer après l'avoir trouvé
        }
        else
            write(clientSocket, "Entrée non trouvée.\n", 19);
    }
    // Ajoutez ici la logique pour d'autres commandes
}

    // Code pour ajouter une nouvelle entrée à la liste chaînée
void addEntry(const char *string) 
{
    Entry *newEntry = (Entry *)malloc(sizeof(Entry));
    if (!newEntry) 
    {
        perror("Erreur d'allocation de mémoire");
        return;
    }
    newEntry->order = ++orderCounter;
    newEntry->string = strdup(string);
    newEntry->timestamp = time(NULL);

    // Ajouter à la fin de la liste pour garder l'ordre chronologique
    if (head == NULL) 
    {
        head = newEntry;
        newEntry->next = NULL;
    }
    else 
    {
        Entry *current = head;
        while (current->next != NULL) 
            current = current->next;
        current->next = newEntry;
        newEntry->next = NULL;
    }
}

char *formatTimestamp(time_t timestamp, char *str, size_t maxSize) 
{
    struct tm *tm = localtime(&timestamp);
    strftime(str, maxSize, "%Y-%m-%d %H:%M:%S", tm);
    return str;
}

    // Code pour supprimer une entrée de la liste chaînée
void deleteEntry(int order) 
{
    Entry *current = head;
    Entry *previous = NULL;

    while (current != NULL) 
    {
        if (current->order == order) 
        {
            if (previous == NULL)
                head = current->next;
            else
                previous->next = current->next;
            free(current->string);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

    // Code pour trouver une entrée par son numéro d'ordre
Entry *findEntryByOrder(int order) 
{
    Entry *current = head;
    while (current != NULL) 
    {
        if (current->order == order)
            return current;
        current = current->next;
    }
    return NULL;
}

    // Code pour trouver une entrée par sa position
Entry *findEntryByPosition(int position) 
{
    Entry *current = head;
    int count = 0;

    while (current != NULL) {
        if (++count == position) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

    // Code pour lister toutes les entrées et les envoyer au client
void listEntries(int clientSocket) 
{
    char buffer[1024];
    Entry *current = head;
    int count = 0;

    while (current != NULL) 
    {
        char timeStr[30];
        formatTimestamp(current->timestamp, timeStr, sizeof(timeStr));

        snprintf(buffer, sizeof(buffer), "Order: %d, String: %s, Timestamp: %s\n",
                 current->order, current->string, timeStr);
        write(clientSocket, buffer, strlen(buffer));
        current = current->next;
        count++;
    }

    if (count == 0) {
        write(clientSocket, "Aucune entrée trouvée.\n", 24);
    }
}

    // Code pour libérer toute la mémoire utilisée par la liste chaînée
void clearAllEntries() 
{
    Entry *current = head;
    while (current != NULL) 
    {
        Entry *temp = current;
        current = current->next;
        free(temp->string);
        free(temp);
    }
    head = NULL;
    orderCounter = 0;
}

    // Code pour arrêter le serveur TCP
void stopServer() 
{
    close(serverSocket);
}

void cleanup() 
{
    stopServer();
    clearAllEntries();
}
