#include "../includes/ft_printf.h"

void 	init_flags(t_flags *tFlags)
{
	tFlags->type = 0;
	tFlags->width = 0;
	tFlags->zero = 1;
	tFlags->hash = 0;
	tFlags->minus = 0;
	tFlags->plus = 0;
	tFlags->prec = -1;
	tFlags->neg = 0;
	tFlags->space = 0;
	tFlags->count = 0;
	tFlags->total = 0;
}
void 	check_width(char **format, t_flags *tFlags)
{
	if (*(*format - 1) == '.')
	{
		tFlags->prec = ft_atoi(&(*(*format)));
		(*format) += (ft_getlen(tFlags->prec) - 1);
	}
	if(*(*format) != '0' && *(*format - 1) != '.' && tFlags->prec == -1)
	{
		tFlags->width = ft_atoi(&(*(*format)));
		(*format) += (ft_getlen(tFlags->width) - 1);
	}
}

void      check_flags(char **format, t_flags *tFlags)
{
    if (*(*format) == 32)
        tFlags->space = 1;
    if (*(*format) == 43)
        tFlags->plus = 1;
    if (*(*format) == 45)
        tFlags->minus = 1;
    if (*(*format) == '0' && *(*format - 1) != 46)
        tFlags->zero = 0;
    if (*(*format) == '#')
    	tFlags->hash = 1;
    if (*(*format) == '.' && !(ft_isdigit((*(*format + 1)))))
			tFlags->prec = -2;
    if ((ft_isdigit(*(*format))) == 1)
        check_width(&(*format), tFlags);
}

void 	check_types(char **format, t_flags *tFlags)
{
	if (*(*format) == 'h' && *(*format - 1) != 'h')
		tFlags->type = TYPE_H;
	if (*(*format) == 'h' && *(*format + 1) == 'h')
		tFlags->type = TYPE_HH;
	if (*(*format) == 'l' && *(*format + 1) != 'l')
		tFlags->type = TYPE_L;
	if (*(*format) == 'l' && *(*format + 1) == 'l')
		tFlags->type = TYPE_LL;
	if (*(*format) == 'L')
		tFlags->type = TYPE_LF;
}

void	check_format(va_list ft_printf_list, char **format, t_flags *tFlags)
{
    if (*(*format) == '%')
        ft_print_percent(tFlags);
    if (*(*format) == 's')
        type_s(ft_printf_list, tFlags);
    if (*(*format) == 'c')
        type_c(ft_printf_list, tFlags);
    if (*(*format) == 'd' || *(*format) == 'i')
        type_d(ft_printf_list, tFlags);
    if (*(*format) == 'f')
        type_f(ft_printf_list, tFlags);
    if (*(*format) == 'o')
    	type_o(ft_printf_list, tFlags);
    if (*(*format) == 'u')
    	type_u(ft_printf_list, tFlags);
    if (*(*format) == 'x')
		type_x(ft_printf_list, tFlags, "0123456789abcdef");
    if (*(*format) == 'X')
		type_x(ft_printf_list, tFlags, "0123456789ABCDEF");
    if (*(*format) == 'p')
		type_p(ft_printf_list, tFlags, "0123456789abcdef");
}
