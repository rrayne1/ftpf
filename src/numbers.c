#include "../includes/ft_printf.h"

void	ft_get_nb(va_list ft_printf_list, intmax_t *nb, t_flags *tFlags)
{
	*nb = va_arg(ft_printf_list, intmax_t);
	if (tFlags->type == TYPE_H)
		*nb = (short int)*nb;
	else if (tFlags->type == TYPE_HH)
		*nb = (char)*nb;
	else if(tFlags->type == 3)
		*nb = (long int)*nb;
	else if (tFlags->type == TYPE_LL)
		*nb = (long long int)*nb;
	else if (tFlags->type == 0)
		*nb = (int)*nb;
}

void	ft_get_nb_u(va_list ft_printf_list, uintmax_t *nb, t_flags *tFlags)
{
	*nb = va_arg(ft_printf_list, uintmax_t);
	if (tFlags->type == TYPE_H)
		*nb = (unsigned short int)*nb;
	else if (tFlags->type == TYPE_HH)
		*nb = (unsigned char)*nb;
	else if(tFlags->type == TYPE_L)
		*nb = (unsigned long int)*nb;
	else if (tFlags->type == TYPE_LL)
		*nb = (unsigned long long int)*nb;
	else if (tFlags->type == 0)
		*nb = (unsigned int)*nb;
}

int		ft_getsize(intmax_t n, t_flags *tFlags)
{
	intmax_t	len;

	len = 0;
	//if (n < 0)
	//	tFlags->neg = 1;
	tFlags->tmp = 1;
	if (n == 0)
	{
		len = 1;
		return (len);
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_get_size_u(uintmax_t nb, uintmax_t length, int *size)
{
	*size += 1;
	while (nb >= length)
	{
		nb /= length;
		*size += 1;
	}
}

void 	ft_putnbr_base(uintmax_t nb, char *str, uintmax_t length)
{
	if (nb >= length)
		ft_putnbr_base(nb / length, str, length);
	ft_write_char(str[nb % length], 1);
}