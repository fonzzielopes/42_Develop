service mysql start
service php7.3-fpm start
service nginx start


# NGINX
        rm var/www/html/index.nginx-debian.html
		cp srcs/nginx.conf etc/nginx/sites-available/html
		ln -s etc/nginx/sites-available/html etc/nginx/sites-enabled/html
		rm -rf /etc/nginx/sites-enabled/default

# SLL
mkdir ~/mkcert && cd ~/mkcert && \
	wget https://github.com/FiloSottile/mkcert/releases/download/v1.4.3/mkcert-v1.4.3-linux-amd64 && \
	mv mkcert-v1.4.3-linux-amd64 mkcert && chmod +x mkcert && \
	./mkcert -install && ./mkcert html
	cd /

echo "CREATE DATABASE wordpress;"| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;"| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password
echo "update mysql.user set plugin='' where user='root';"| mysql -u root --skip-password

# PHPMYADMIN
mkdir -p /var/www/html/phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-all-languages.tar.gz
tar -xf phpMyAdmin-5.1.0-all-languages.tar.gz 
mv config.inc.php /var/www/html/phpmyadmin/
rm -rf phpMyAdmin-5.1.0-all-languages.tar.gz

# WORDPRESS
wget https://wordpress.org/latest.tar.gz
tar -xzf latest.tar.gz
mv wp-config.php /var/www/html/ 
rm -rf latest.tar.gz

# Giving nginx's user-group rights over page files
chown -R www-data /var/www/*
chmod -R 755 /var/www/*

bash