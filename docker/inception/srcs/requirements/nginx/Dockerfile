


FROM debian:buster


RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y nginx
RUN apt-get install -y openssl

RUN mkdir -p /etc/nginx/ssl/private
RUN mkdir -p /etc/nginx/ssl/certs
RUN mkdir -p /var/run/nginx



RUN openssl req -newkey rsa:4096 -days 42 -nodes -x509 -out /etc/nginx/ssl/certs/inception.crt -keyout /etc/nginx/ssl/private/inception.key -subj "/C=FR/ST=Paris/L=Paris/O=42/OU=42Paris/CN=jmetezea.42.fr/UID=jmetezea"

COPY conf/nginx.conf /etc/nginx/nginx.conf

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html


CMD ["nginx", "-g", "daemon off;"]



