FROM alpine:3.12

RUN apk update 
RUN apk upgrade

RUN apk add bash influxdb supervisor openrc libc6-compat wget

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz --strip-components=2 -C /

COPY ./configs/telegraf.conf /etc/telegraf/
COPY ./configs/supervisord.conf /etc/supervisor.conf
COPY ./configs/supervisor_start.sh /

EXPOSE 8086

CMD bash supervisor_start.sh