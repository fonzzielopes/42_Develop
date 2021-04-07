# File to start the docker script
docker build -t ft_server . 
docker run --rm --name myserver -d -p 80:80 -p 443:443 ft_server
docker exec -it myserver bash