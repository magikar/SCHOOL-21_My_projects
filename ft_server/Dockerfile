# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 15:29:20 by tmagikar          #+#    #+#              #
#    Updated: 2021/02/27 15:29:37 by tmagikar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get -y install vim
RUN apt-get -y install wget
RUN apt-get -y install mariadb-server
RUN apt-get -y install nginx
RUN apt-get -y install php7.3-fpm php7.3-common php7.3-mysql php7.3-gmp php7.3-curl php7.3-intl php7.3-mbstring php7.3-xmlrpc php7.3-gd php7.3-xml php7.3-cli php7.3-zip php7.3-soap php7.3-imap

RUN mkdir /var/www/html/index
RUN mkdir /var/www/html/phpmyadmin
RUN wget https://wordpress.org/latest.tar.gz
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0-rc1/phpMyAdmin-5.1.0-rc1-all-languages.tar.gz
RUN tar zxvf phpMyAdmin-5.1.0-rc1-all-languages.tar.gz --strip-components 1 -C /var/www/html/phpmyadmin
RUN tar zxvf latest.tar.gz -C ./var/www/html/


RUN chmod -R 777 /var/www/*

COPY ./srcs/start.sh ./
COPY ./srcs/nginx.conf ./etc/nginx/sites-available/default
COPY ./srcs/wp-config.php ./var/www/html/wordpress/wp-config.php
COPY ./srcs/config.inc.php ./var/www/html/phpmyadmin/config.inc.php
COPY ./srcs/index.php ./var/www/html/index/index.php

EXPOSE 80 443

CMD bash start.sh && bash
