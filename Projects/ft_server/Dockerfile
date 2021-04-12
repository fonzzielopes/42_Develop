# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes <alopes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 16:17:12 by alopes            #+#    #+#              #
#    Updated: 2021/04/12 13:01:56 by alopes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get -y install wget -y \
    nginx \
    mariadb-server \
    php-mysql php-fpm php-pdo php-gd php-cli php-mbstring 
 #&& rm -rf /var/lib/apt/lists/*

COPY ./ srcs ./
COPY srcs/*.sh ./

EXPOSE 80 443

CMD bash init.sh 