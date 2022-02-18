FROM alpine:3.12

RUN apk update 
RUN apk upgrade

RUN apk add bash supervisor libc6-compat openssl openrc nginx

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz --strip-components=2 -C /

RUN mkdir -p /run/nginx

COPY ./configs/telegraf.conf /etc/telegraf/
COPY ./configs/nginx.conf /etc/nginx/conf.d/default.conf
COPY ./configs/supervisor.conf /etc/
COPY ./configs/supervisor_start.sh /

EXPOSE 80 443

CMD bash supervisor_start.sh
