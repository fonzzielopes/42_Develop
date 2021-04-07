# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes <alopes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 16:17:12 by alopes            #+#    #+#              #
#    Updated: 2021/04/07 16:12:27 by alopes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get -y install wget -y \
    nginx \
    mariadb-server \
    php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring \
 && rm -rf /var/lib/apt/lists/*

COPY srcs/init.sh ./
COPY srcs/nginx.config /tmp/
COPY srcs/config.inc.php /var/www/html/phpmyadmin
COPY srcs/wp-config.php /var/www/html/wordpress

EXPOSE 80 443

CMD bash init.sh