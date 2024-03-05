#!/bin/bash
set -e

# Attendre que la base de données PostgreSQL soit prête
while ! nc -z db 5432; do
  echo "Attente du démarrage de la base de données PostgreSQL..."
  sleep 5
done

# Exécuter les migrations
python manage.py makemigrations
python manage.py migrate

# Collecter les fichiers statiques pour admin
python manage.py collectstatic --skip-checks --noinput

python manage.py shell < create_superuser.py

# Démarrer le serveur Django
python manage.py runserver 0.0.0.0:${DJANGO_PORT}
