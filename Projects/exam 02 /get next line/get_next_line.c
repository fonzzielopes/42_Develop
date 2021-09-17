#include <stdlib.h>
#include <unistd.h>

int	get_next_line(char **line)
{
	char	*holder;
	char	c;
	int		rtrn;
	int		i;

	holder = malloc(9000 * sizeof(char));
	i = 0;
	holder[0] = '\0';
	while (1)
	{
		rtrn = read(0, &c, 1);
		if (rtrn <= 0 || c == '\n')
			break ;
		holder[i++] = c;
	}
	holder[i] = '\0';
	*line = holder;
	if (rtrn > 1)
		rtrn = 1;
	return (rtrn);
}
