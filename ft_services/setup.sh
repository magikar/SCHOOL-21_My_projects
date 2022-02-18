#!/bin/sh

minikube stop
minikube delete

minikube --driver=virtualbox --memory='3000' --disk-size 30000MB start

minikube addons enable metallb
minikube addons enable dashboard

eval $(minikube docker-env)

./srcs/nginx/docker_build_nginx.sh
./srcs/wordpress/docker_build_wordpress.sh
./srcs/phpmyadmin/docker_build_phpmyadmin.sh
./srcs/mysql/docker_build_mysql.sh
./srcs/influxdb/docker_build_influxdb.sh
./srcs/grafana/docker_build_grafana.sh
./srcs/ftps/docker_build_ftps.sh

./srcs/apply_yaml.sh

# sleep 10
# kubectl get pods
