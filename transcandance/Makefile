# Chemin vers le fichier docker-compose.yml
DC = docker-compose.yml

# Commandes Makefile
all: build up

build:
	mkdir -p volumes/pg_data
	docker-compose -f $(DC) build
	docker-compose -f $(DC) up -d

up:
	@docker-compose -f $(DC) up -d

down:
	@docker-compose -f $(DC) down

restart-nginx:
	@docker-compose -f $(DC) restart nginx

restart-db:
	@docker-compose -f $(DC) restart db

restart-pgadmin:
	@docker-compose -f $(DC) restart pgadmin

restart-front:
	@docker-compose -f $(DC) restart front

restart-back:
	@docker-compose -f $(DC) restart back

c:
	@docker-compose -f $(DC) down
	@docker volume prune -f
	@docker network prune -f

fc:
	@docker-compose -f $(DC) down -v
	@docker volume prune -f
	@docker network prune -f
	@docker system prune --all -f

re: c all

refc: fc all

.PHONY: all build up c fc re refc restart-nginx
