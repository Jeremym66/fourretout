#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>

#define PATH "exercice.ctl"
#define PORT 4849

typedef struct Entry {
    int     order;
    char    *string;
    time_t  timestamp;
    struct Entry *next;
} Entry;

Entry *head = NULL;
int orderCounter = 0;
int serverSocket;
volatile sig_atomic_t shutdownRequested = 0;

// Prototypes des fonctions
void startDaemon();
void handleSignal(int sig);
void *monitorFile(void *arg);
void NetworkRequests();
void processCommand(int clientSocket, char *command);
void addEntry(const char *string);
void deleteEntry(int order);
Entry *findEntryByOrder(int order);
Entry *findEntryByPosition(int position);
void listEntries(int clientSocket);
void clearAllEntries();
void stopServer();
void cleanup();
char *formatTimestamp(time_t timestamp, char *str, size_t maxSize);