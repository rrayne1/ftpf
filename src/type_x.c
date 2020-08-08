#include "../includes/ft_printf.h"

void ft_display_precision(t_flags *tFlags, char *cont)
{
	if (tFlags->width == 0 && tFlags->hash && tFlags->type != p)
	{
		tFlags->prec -= 2;
		tFlags->total += 2;
	}
	if (tFlags->zero == 0)
		tFlags->zero = 1;
	if (!tFlags->minus && tFlags->width > 0)
	{
		ft_print_width(tFlags);
		tFlags->total += tFlags->width;
		tFlags->width = 0;
	}
	if (tFlags->hash)
	{
		ft_write(cont, 2);
		tFlags->hash = 0;
	}
	while (--tFlags->prec >= 0)
		ft_write("0", 1);
}

void ft_display_width(t_flags *tFlags, char *cont)
{
	if (!tFlags->minus && !tFlags->hash && !tFlags->zero)
		ft_print_width(tFlags);
	if (!tFlags->minus && tFlags->zero)
		ft_print_width(tFlags);
	if (tFlags->hash)
		ft_write(cont, 2);
	if (!tFlags->minus && (tFlags->hash || tFlags->prec < -1) && !tFlags->zero)
		ft_print_width(tFlags);
}

void ft_display_x(uintmax_t nb, int *size, t_flags *tFlags, char *base)
{
	char 	*cont;
	int 	width;

	width = 0;
	cont = ft_strchr(base, 'a') ? "0x" : "0X";
	if (tFlags->prec > 0)
		tFlags->zero = 1;
	check_zero(nb, size, tFlags);
	ft_precision(tFlags, *size);
	if (tFlags->prec > 0)
		ft_display_precision(tFlags, cont);
	if (tFlags->prec <= 0)
		ft_display_width(tFlags, cont);
	if (*size > 0 && tFlags->count != 1)
		ft_putnbr_base((uintmax_t)nb, base, 16);
	if (nb == 0 && (tFlags->prec == -1) && tFlags->type == p)
	{
		ft_write("0", 1);
		tFlags->total += 1;
	}
	while (++width <= tFlags->width && tFlags->minus)
		ft_write(" ", 1);
}

int		type_x(va_list ft_printf_list, t_flags *tFlags, char *base)
{
	uintmax_t 	nb;
	int			size;

	ft_get_nb_u(ft_printf_list, &nb, tFlags);
	size = 0;
	ft_get_size_u((uintmax_t)nb, ft_strlen(base), &size);
	tFlags->width -= size;
	if (nb == 0)
		tFlags->hash = 0;
	if (tFlags->hash && nb != 0)
	{
		tFlags->total += 2;
		tFlags->width -= 2;
	}
	ft_display_x(nb, &size, tFlags, base);
	if (tFlags->prec <= 0)
		total_dit(nb, size, tFlags);
	tFlags->count += 1;
	return (tFlags->total);
}