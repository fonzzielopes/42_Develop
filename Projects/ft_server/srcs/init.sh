#!/bin/bash

service php7.3-fpm start

#config access
# Giving nginx's user-group rights over page files
chown -R www-data /var/www/*
chmod -R 755 /var/www/*

# Generate website folder
mkdir /var/www/localhost && touch /var/www/localhost/index.php
echo "<?php phpinfo(); ?>" >> /var/www/localhost/index.php

#SSL certificate
mkdir /etc/nginx/ssl
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-subj '/C=PT/ST=LS/L=Lisboa/O=42Lisboa/CN=alopes' \
	-keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt

#SQL config
service mysql start
echo "CREATE DATABASE wordpress;"| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;"| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password
echo "update mysql.user set plugin='' where user='root';"| mysql -u root --skip-password
service nginx start

#PHP config 
mkdir -p /var/www/localhost/phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
tar -xf phpMyAdmin-5.0.1-english.tar.gz 
mv /var/config.inc.php /var/www/localhost/phpmyadmin/
rm -rf phpMyAdmin-5.0.1-english.tar.gz

#Wordpress config
wget https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
mv wordpress/ /var/www/localhost
mv /var/wp-config.php /var/www/localhost/wordpress
rm -rf latest.tar.gz

bash