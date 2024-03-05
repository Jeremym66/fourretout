FROM python:3.9

WORKDIR /api42

RUN apt-get update && apt-get install -y postgresql-client netcat-openbsd
COPY requirements.txt .

RUN pip install -r requirements.txt
RUN	pip install pyotp
RUN	pip install qrcode

COPY migrate.sh .

RUN chmod +x migrate.sh

COPY . .

CMD ["./migrate.sh"]
