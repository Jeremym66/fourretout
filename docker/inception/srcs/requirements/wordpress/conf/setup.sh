#!/bin/bash
# La ligne ci-dessus spécifie que le script doit être exécuté avec le shell Bash

# Pause de 10 secondes
sleep 10

# Déplace le fichier "index.html" vers le répertoire "/var/www/wordpress/"
mv /conf/index.html /var/www/wordpress/index.html

wp core install --url=$DOMAIN_NAME \
    --title=$SITE_TITLE \
    --admin_user=$SITE_ADMIN_USER \
    --admin_password=$SITE_ADMIN_PASSWORD \
    --admin_email=$SITE_ADMIN_EMAIL \
    --allow-root --path='/var/www/wordpress'

# Create a user using wp-cli
wp user create --allow-root --role=author $SITE_USER1_LOGIN $SITE_USER1_MAIL \
    --user_pass=$SITE_USER1_PASS --path='/var/www/wordpress' >> /log.txt

# Vérifie si le répertoire "/run/php" n'existe pas
if [ ! -d /run/php ]; then
    mkdir /run/php
fi

# Exécute le gestionnaire de processus PHP-FPM (PHP-FastCGI Process Manager) en mode "foreground" (-F)
/usr/sbin/php-fpm7.3 -F
