#include "../includes/ft_printf.h"

void 	ft_precision(t_flags *tFlags, int size)
{
	if (tFlags->prec > 0)
		tFlags->prec -= size;
	if (tFlags->width > 0 && tFlags->prec > 0)
		tFlags->width -= tFlags->prec;
	if (tFlags->prec > 0)
		tFlags->total += tFlags->prec;

}

int 	check_zero(uintmax_t nb, int *size, t_flags *tFlags)
{
	if (nb == 0 && (tFlags->prec == -2 || tFlags->prec == 0 || \
			tFlags->hash))
	{
		if (tFlags->width > 0)
			tFlags->width += *size;
		*size = 0;
		tFlags->count = 1;
		return (-1);
	}
	return (0);
}