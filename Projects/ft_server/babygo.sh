docker build -t ft_server . 
docker run --rm --name myserver -itp 80:80 -p 443:443 ft_server
#docker exec -it myserver bash