#FROM utilisable quune fois // image de base
FROM ubuntu:18.04

#Permet dexecuter des commandes 1 run = 1 layer donc a limiter
#afin de reduire la taille de limage docker
RUN apt-get update -yq
RUN apt-get install curl gnupg -yq
RUN curl -sL https://deb.nodesource.com/setup_10.x | bash
RUN apt-get install nodejs -yq 
RUN apt-get clean -y

#creer un dossier afin de copier ou dl des fichiers dans limage
ADD . /app/

#remplace cd afin dexecuter les commandes suivantes dans le bon dossier
WORKDIR /app

#permet dinstaller le package Node.js
RUN npm install

#EXPOSE permet d'indiquer le port sur lequel votre application écoute. 
#VOLUME permet d'indiquer quel répertoire vous voulez partager avec votre host.
EXPOSE 2368
VOLUME /app/logs

#permet de start le node.js
CMD npm run start