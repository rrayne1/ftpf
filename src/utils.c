#include "../includes/ft_printf.h"

void 	ft_write_char(char c, int size)
{
	ft_write(&c, size);
}

int 	ft_write(void *s, int size)
{
	char 	*str;
	int 	i;

	i = 0;
	str = s;
	while (i < size)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (size);
}
