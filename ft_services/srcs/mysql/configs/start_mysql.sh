#!/bin/sh

rc default
/etc/init.d/mariadb setup
rc-service mariadb start

mysql -u root << EOF
  CREATE DATABASE wordpress;
  DROP DATABASE test;
  CREATE USER 'admin'@'%' IDENTIFIED BY 'admin';
  GRANT ALL PRIVILEGES ON wordpress.* TO 'admin'@'%';
  FLUSH PRIVILEGES;
EOF
mysql -u root wordpress < wordpress.sql

rc-service mariadb stop
/usr/bin/supervisord
