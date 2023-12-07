gcc -o monprog test1.c -lpthread
./monprog #&
rm monprog

# pour se connecter au client:
# telnet 127.0.0.1 4848
# commande help disponible 


#affiche le pid du processus
#   pgrep monprog

# pour kill le Daemon
#kill <PID>

