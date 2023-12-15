NAME = inception
CONFIGS_FOLDER = ./srcs/requirements
COMPOSE_FILE = ./srcs/docker-compose.yml
ENV = ./srcs/.env
BASEYML = ./srcs/tools/base.yml
LOGIN = $(shell whoami)

all: build run

# Build the docker images in the docker-compose.yml file
build:
	mkdir -p ~/data/mariadb
	mkdir -p ~/data/wordpress
	sudo docker-compose -f $(COMPOSE_FILE) build
	@echo "\n\nInception is ready to be launched."

# Run the docker containers in the docker-compose.yml file
run:
	sudo docker-compose -f $(COMPOSE_FILE) up -d
	@echo "\n\nInception is now running on https://${LOGIN}.42.fr."

stop:
	sudo docker-compose -f $(COMPOSE_FILE) stop

# Launch the tests
test: build run

# Stop and remove the docker containers
clean: stop
	sudo docker-compose -f $(COMPOSE_FILE) down -v

# Remove the docker images
fclean: clean
	@if [ -n "$$(sudo docker ps -a -q)" ]; then sudo docker rm -f $$(sudo docker ps -a -q); fi
	@if [ -n "$$(sudo docker images -q)" ]; then sudo docker rmi -f $$(sudo docker images -q); fi
	@if [ -n "$$(sudo docker volume ls -q)" ]; then sudo docker volume prune -f; fi
	sudo rm -rf ~/data/*

re: fclean all


# modifier /etc/hosts pour avoir jmetezea.42.fr au lieu de localhost

# https://jmetezea.42.fr
# https://jmetezea.42.fr/index.html
# https://jmetezea.42.fr/index.html

# pour entrer dans mariadb 
# 	docker exec -it nom_du_conteneur_mariadb /bin/bash
# mode root 
# 	mysql -u root -p
# afficher les users dans maria db
# 	SELECT user, host FROM mysql.user;
# ajouter un utilisateur
#	CREATE USER 'nom_utilisateur'@'localhost' IDENTIFIED BY 'mot_de_passe';
# exit; et exit pour quitter root et mariadb