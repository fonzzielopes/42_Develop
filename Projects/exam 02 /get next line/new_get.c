#include <stdlib.h>
#include <unistd.h>

int get_next_line(char **line)
{
	char	*holder;
	char	c;
	int		result;
	int		i;

	holder = malloc(9000 * sizeof(char));
	holder[0] = '\0';
	i = 0;
	while (1)
	{
		result = read(0, &c, 1);
		if (result <= 0 || c == '\n')
			break ;
		holder[i++] = c;
	}
	holder[i] = '\0';
	*line = holder;
	if (result > 1)
		result = 1;
	return(result);
}
