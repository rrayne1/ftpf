#include "../includes/ft_printf.h"

int 		start(va_list ft_printf_list, char **format)
{
	t_flags		*tFlags;
	int tres;

	tFlags = (t_flags *)malloc(sizeof(t_flags));
	init_flags(tFlags);
	while(tFlags->count == 0)
	{
        check_flags(format, tFlags);
        check_types(format, tFlags);
        check_format(ft_printf_list, format, tFlags);
        (*format)++;
    }
	tres = tFlags->total;
	free(tFlags);
	return (tres);
}

int		check_val(char *str)
{
	if (ft_strchr(str, 'd'))
		return (1);
	else if (ft_strchr(str, 'i'))
		return (1);
	else if (ft_strchr(str, 'o'))
		return (1);
	else if (ft_strchr(str, 'u'))
		return (1);
	else if (ft_strchr(str, 'x'))
		return (1);
	else if (ft_strchr(str, 'X'))
		return (1);
	else if (ft_strchr(str, 's'))
		return (1);
	else if (ft_strchr(str, 'c'))
		return (1);
	else if (ft_strchr(str, 'p'))
		return (1);
	else if (ft_strchr(str, 'f'))
		return (1);
	else if (ft_strchr(str, '%'))
		return (1);
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list 	ft_printf_list;
	int 		res;
	char 		*str;

	res = 0;
	va_start(ft_printf_list, format);
	str = (char *)format;
	while (*str != 0)
	{
		if (*str == '%')
		{
			str++;
			if(!(check_val(str)))
				return (0);
			res += start(ft_printf_list, &str);
		}
		else
			res += ft_print_str(&str);
	}
	va_end(ft_printf_list);
	return (res);
}
int	main(void)
{
	int a = 0;
	int b = 0;


	a = printf("%Lf", -1.42l);
	printf("\n");
	b = ft_printf("tak nado %s", "lol");
	printf("\n %d %d \n", a, b);

	return (0);
}