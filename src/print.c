#include "../includes/ft_printf.h"

void	ft_print_width(t_flags *tFlags)
{
	int 	i;

	i = 0;
	while (i++ < tFlags->width)
	{
		if (tFlags->zero == 1 || tFlags->prec > 0)
			ft_write(" ", 1);
		else if (tFlags->zero == 0)
			ft_write("0", 1);
	}
}

void 		ft_print_sign(t_flags *tFlags)
{
	if (tFlags->neg == 0)
	{
		if (tFlags->plus == 1)
			ft_write("+", 1);
		if (tFlags->space == 1)
			ft_write(" ", 1);
	}
	if (tFlags->neg == 1)
		ft_write("-", 1);

}

int   ft_print_percent(t_flags *tFlags)
{
	if (tFlags->width > 0)
		tFlags->width -= 1;
	tFlags->zero = 1;
	if (!tFlags->minus)
		ft_print_width(tFlags);
	ft_write("%", 1);
	tFlags->total = (tFlags->width > 0 ? tFlags->width + 1 : 1);
	if (tFlags->minus)
		ft_print_width(tFlags);
	tFlags->count += 1;
	return (tFlags->total);
}

int 		ft_print_str(char **format)
{
	int		len;

	if (ft_strchr(*format, '%'))
		len = (int)(ft_strchr(*format, '%') - *format);
	else
		len = (int)(ft_strlen(*format));
	ft_write(*format, len);
	(*format) += len;
	return (len);
}