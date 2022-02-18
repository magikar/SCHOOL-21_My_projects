#!/bin/sh

cd srcs
kubectl apply -f configmap.yaml
#  nginx
kubectl apply -f nginx/configs/nginx_service.yaml

#  wordpress
kubectl apply -f wordpress/configs/wordpress_service.yaml

#  phpmyadmin
kubectl apply -f phpmyadmin/configs/phpmyadmin_service.yaml

#  mysql
kubectl apply -f mysql/configs/mysql_service.yaml

#  influxdb
kubectl apply -f influxdb/configs/influxdb_service.yaml

#  grafana
kubectl apply -f grafana/configs/grafana_service.yaml

#  ftps
kubectl apply -f ftps/configs/ftps_service.yaml
