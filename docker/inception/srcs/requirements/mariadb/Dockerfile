FROM debian:buster

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y mariadb-server


RUN mkdir -p /conf && chmod 755 /conf
COPY /conf/creatDataBase.sh /conf/creatDataBase.sh
COPY /conf/my.cnf /etc/mysql/mariadb.conf.d/50-server.cnf


ENTRYPOINT ["/bin/bash", "/conf/creatDataBase.sh"]

EXPOSE 3306
