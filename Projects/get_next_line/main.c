#include "get_next_line.h"

int main (void)
{
	char *line;

	printf("%zd\n", read(42, 0 , 0));

	printf("%d", get_next_line(42, &line));
}
