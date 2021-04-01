# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes <alopes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 16:17:12 by alopes            #+#    #+#              #
#    Updated: 2021/04/01 16:17:48 by alopes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update && apt-get upgrade -y \
&& apt-get -y install wget && apt-get -y install nginx \

WORKDIR /ft_server

CMD ["sh"]

