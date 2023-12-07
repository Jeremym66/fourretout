#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <sys/wait.h>


#define FILE_PATH "/tmp/exercice.ctl"
#define PORT 4848
#define MAX_ENTRIES 100

struct Entry
{
    int number;
    char string[256];
    char date[20];
};

struct Entry entries[MAX_ENTRIES];

int entryCount = 0;
int shutdownRequested = 0;

void process_string(const char *str)
{
    // Vérifier si nous avons atteint la capacité maximale
    if (entryCount >= MAX_ENTRIES)
    {
        fprintf(stderr, "Capacité maximale atteinte, certaines entrées seront ignorées.\n");
        return;
    }
    // Mémoriser l'entrée
    entries[entryCount].number = entryCount + 1;
    strncpy(entries[entryCount].string, str, sizeof(entries[entryCount].string) - 1);

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(entries[entryCount].date, sizeof(entries[entryCount].date), "%Y/%m/%d %H:%M:%S", tm_info);

    entryCount++;
}

void handle_client(int client_socket)
{
    char buffer[256];
    ssize_t bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) 
    {
        buffer[bytes_received] = '\0';
        // Traiter la commande
        if (buffer[0] == '#') 
        {
            int index = 0;
            int nb = 0;
            int no_entry = 0;
            
            sscanf(buffer + 1, "%d", &nb);
            while (index <= entryCount) 
            {
                // Récupérer les détails de l'entrée
                struct Entry * entry = &entries[index - 1];
                if (nb == entry->number)
                {
                    // Envoyer les détails au client
                    dprintf(client_socket, "> Number : %d\n", entry->number);
                    dprintf(client_socket, "> Position : %d\n", index);
                    dprintf(client_socket, "> Date : %s\n", entry->date);
                    dprintf(client_socket, "> String : %s\n", entry->string);
                    no_entry++;
                    break;
                }
                index++;
            }
            if (no_entry == 0)
                dprintf(client_socket, "Entrée non valide.\n");
            else
            {
                //Supprimer l'entrée de la mémoire
                for (int i = index - 1; i < entryCount - 1; ++i) 
                {
                    entries[i] = entries[i + 1];
                }
                entryCount--;
            }

        }
        else if (strncmp(buffer, "@@", 2) == 0)
        {
            struct Entry * entry = &entries[0];
            if (entryCount >= 1)
            {
                int i = 0; 
                while (i < entryCount) 
                {
                    dprintf(client_socket, "> Number : %d\n", entries[i].number);
                    dprintf(client_socket, "> Position : %d\n", i + 1);
                    dprintf(client_socket, "> Date : %s\n", entries[i].date);
                    dprintf(client_socket, "> String : %s\n", entries[i].string);
                    i++;
                }
            }
        }
        else if (strncmp(buffer, "delete", 6) == 0)
        {
            if (entryCount >= 1)
            {
                int i = 0; 
                while (i < entryCount) 
                {
                    entries[i] = entries[i + entryCount];
                    i++;
                }
            }
            entryCount = 0;
            dprintf(client_socket, "Le tableau a ete efface\n");
        }
        else if (buffer[0] == '@' && buffer[2] == '-') 
        {
            int index1 = buffer[1] - 48;
            int index2 = buffer[3] - 48;

            while (index1 >= 1 && index1 <= index2) 
            {
                // Récupérer les détails de l'entrée
                struct Entry * entry = &entries[index1 - 1];

                // Envoyer les détails au client
                dprintf(client_socket, "> Number : %d\n", entry->number);
                dprintf(client_socket, "> Position : %d\n", index1);
                dprintf(client_socket, "> Date : %s\n", entry->date);
                dprintf(client_socket, "> String : %s\n", entry->string);

                index1++;
            } 
        }
        else if (buffer[0] == '@') 
        {
            int index = 0;
            
            sscanf(buffer + 1, "%d", &index);
            if (index >= 1 && index <= entryCount) 
            {
                // Récupérer les détails de l'entrée
                struct Entry * entry = &entries[index - 1];

                // Envoyer les détails au client
                dprintf(client_socket, "> Number : %d\n", entry->number);
                dprintf(client_socket, "> Position : %d\n", index);
                dprintf(client_socket, "> Date : %s\n", entry->date);
                dprintf(client_socket, "> String : %s\n", entry->string);

                // Supprimer l'entrée de la mémoire
                for (int i = index - 1; i < entryCount - 1; ++i) 
                {
                    entries[i] = entries[i + 1];
                }
                entryCount--;
            } 
            else
                dprintf(client_socket, "Entrée non valide.\n");
        }
        
        else if (strncmp(buffer, "exit", 4) == 0)
            break;
        else if (strncmp(buffer, "help", 4) == 0)
        {
            dprintf(client_socket, "tapez #<nombre> pour afficher la string numero <nombre> et l'effacer\n");
            dprintf(client_socket, "tapez @<nombre> pour afficher la string en position <nombre> et leffacer\n");
            dprintf(client_socket, "tapez @<nombre>-<nombre> pour afficher les string en position dans la tranche <nombre>-<nombre> et leffacer\n");
            dprintf(client_socket, "tapez @@ pour afficher la liste des strings\n");
            dprintf(client_socket, "tapez delete pour sortir effacer les donnees\n");
            dprintf(client_socket, "tapez exit pour sortir du client\n");
        }
        else
        {
            dprintf(client_socket, "Commande non valide. tapez help\n");
        }
    }
    close(client_socket);
}

void *monitorFile(void *arg) 
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;

    while (!shutdownRequested) 
    {
        file = fopen(FILE_PATH, "r");
        if (file) 
        {
            while (getline(&line, &len, file) != -1)
            {
                process_string(line);
            //     printf("line ajoutee : %s\n", line);   // a supprimer
            }
            fclose(file);
            file = fopen(FILE_PATH, "w");
            if (file == NULL) 
            {
                perror("Erreur lors de l'ouverture du fichier en mode écriture");
                return NULL;
            }
            fclose(file);
        }
        free(line);
        line = NULL;
        sleep(1);
    }
    return NULL;
}

void    close_daemon(pthread_t monitor, const char * str)
{
    perror(str);
    shutdownRequested = 1;
    pthread_join(monitor, NULL);
    exit(EXIT_FAILURE);
}

void startDaemon() 
{
    pid_t pid = fork();

    if (pid < 0)
        exit(EXIT_FAILURE);

    if (pid > 0)
    {
        // printf("pid parent (daemon): %d\n", getpid());
        exit(EXIT_SUCCESS);
    }
    // printf("pid enfant (daemon): %d\n", getpid());

    setsid();
}

int main() 
{
    startDaemon();

    // Code pour scruter le fichier /tmp/exercice.ctl et mémoriser les entrées
    pthread_t fileMonitorThread;

    if (pthread_create(&fileMonitorThread, NULL, monitorFile, NULL) != 0) 
    {
        perror("Failed to create file monitor thread");
        return 1;
    }

    // Code pour mettre en place le serveur TCP sur le port 4848
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Créer le socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
        close_daemon(fileMonitorThread, "Error creating socket");

    // Initialiser la structure sockaddr_in
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Lier le socket à l'adresse et au port spécifiés
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        close_daemon(fileMonitorThread, "Error binding socket");

    // Mettre en écoute sur le port spécifié
    if (listen(server_socket, 5) == -1) 
        close_daemon(fileMonitorThread, "Error listening on socket");

    // printf("Daemon en attente de connexions sur le port %d...\n", PORT);

    // Boucle principale d'acceptation des connexions
    while (1)
    {
        // Accepter une connexion
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len)) == -1) 
        {
            perror("Error accepting connection");
            continue;
        }
        handle_client(client_socket);
    }
    // shutdownRequested = 1;
    // pthread_join(fileMonitorThread, NULL);
    // close(server_socket);   // Fermes le socket du serveur (ce code ne sera jamais atteint dans ce programme infini)
    return 0;
}
