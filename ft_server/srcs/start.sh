# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 15:30:29 by tmagikar          #+#    #+#              #
#    Updated: 2021/02/27 15:30:34 by tmagikar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Move index file
mv ./var/www/html/index.nginx-debian.html ./var/www/html/index/index.nginx-debian.html

# SSL
mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/localhost.crt -keyout /etc/nginx/ssl/localhost.key -subj "/C=FR/ST=Moscow/L=Balalaika/O=42 School/OU=tmagikar/CN=project_hui"

service mysql start
service php7.3-fpm start

# config mysql
mysql -e "CREATE DATABASE db_tmagikar_wp;"
mysql -e "CREATE USER 'tmagikar'@'localhost' IDENTIFIED BY 'tmagikar';"
mysql -e "GRANT ALL PRIVILEGES ON db_tmagikar_wp.* TO 'tmagikar'@'localhost';"
mysql -e "FLUSH PRIVILEGES;"

service nginx start

sleep infinity