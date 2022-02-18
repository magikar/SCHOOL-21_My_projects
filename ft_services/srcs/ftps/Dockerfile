FROM alpine:3.12

RUN apk update 
RUN apk upgrade 

RUN apk add openssh openssl openrc libc6-compat bash wget vsftpd supervisor

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz --strip-components=2 -C /

RUN mkdir -p home/admin/ && chmod -R 777 home/ && mkdir -p /etc/ssl/private && mkdir -p /etc/ssl/certs && chmod -R 777 /etc/ssl/private && chmod -R 777 /etc/ssl/certs

RUN adduser -D admin && echo "admin:admin" | chpasswd

COPY ./configs/vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY ./configs/telegraf.conf /etc/telegraf/
COPY ./configs/supervisor.conf /etc/supervisor.conf
COPY ./configs/supervisor_start.sh /

EXPOSE 21 42021

CMD bash supervisor_start.sh