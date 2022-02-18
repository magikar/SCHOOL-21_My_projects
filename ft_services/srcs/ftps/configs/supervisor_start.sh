#!/bin/sh

openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/ssl/certs/nginx_host.crt -keyout /etc/ssl/private/nginx_host.key -subj "/C=FR/ST=Moscow/L=Balalaika/O=42 School/OU=tmagikar/CN=gg_project"

supervisord -c /etc/supervisor.conf
