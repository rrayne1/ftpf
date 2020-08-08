#include "../includes/ft_printf.h"

void 	total_str(char *s, size_t *len, t_flags *tFlags)
{
	if(tFlags->prec > 0 && tFlags->prec < (int)ft_strlen(s))
		*len = tFlags->prec;
	else
		*len = ft_strlen(s);
	if (tFlags->prec == -2 || tFlags->prec == 0)
		*len = 0;
	if ((tFlags->width > 0 && s) || ((tFlags->prec > 1) && !s))
		tFlags->width -= *len;
	if (tFlags->prec == -1 && !s)
		tFlags->width -= *len;
	if (tFlags->width > 0)
		tFlags->total += tFlags->width;
}

void 	total_dit(intmax_t nb, int size, t_flags *tFlags)
{
	if (tFlags->total < 0)
		tFlags->total = 0;
	if (tFlags->width == size && size != 0)
		tFlags->total += size + ft_getsize((uintmax_t)(nb), tFlags);
	if (tFlags->width != size && tFlags->width >= 0)
		tFlags->total += size + tFlags->width;
	if (tFlags->width < 0)
		tFlags->total += size;
}
