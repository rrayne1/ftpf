#include "../includes/ft_printf.h"

int 	ft_infinity(t_float *f, t_flags *tFlags)
{
	if (f->nb == INFINITY)
		tFlags->total = ft_write("inf", 3);
	if (f->nb == -INFINITY)
		tFlags->total = ft_write("-inf", 4);
	if (f->nb == NAN)
		tFlags->total = ft_write("nan", 3);
	tFlags->count += 1;
	return (tFlags->total);

}

double 	ft_modulo(long double nb, int *size)
{
	double modulo;

	modulo = 1;
	while ((int)(nb /= 10) != 0 && (*size)++)
		modulo *= 10;
	(*size)++;
	return (modulo);
}

char*	ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	int		len;

	len = (int)(s2 ? ft_strlen(s1) + ft_strlen(s2) : ft_strlen(s1) + 0);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	if (s2)
	{
		ft_strcat(str, s2);
		free(s2);
	}
	free (s1);
	return (str);
}

int	ft_full(t_float *f, t_flags *tFlags)
{
	char	*bf;
	char	*af;
	char	*s;
	intmax_t tmp;

	tmp = (intmax_t)f->nb;
	bf = ft_itoa(tmp);
	f->nb -= tmp;
	if (tFlags->prec > 0)
	{
		if (!(af = ft_strnew(tFlags->prec + 1)))
			return (0);
		ft_full_after(&af, tFlags, f);
	}
	else
		af = 0;
	if (!(s = ft_strjoin_free(bf, af)))
		return (0);
	ft_display_f(s, tFlags);
	free(s);
	return (tFlags->total);
}

int 	get_prec(t_float *f, long double nb, t_flags *tFlags)
{
	long double		tmp;
	int 			tprec;
	int 			tsize;

	if (tFlags->prec == 0 || (tFlags->prec == 1 && !f->type))
		return (f->size = 1);
	tprec = tFlags->prec;
	tsize = 0;
	while (tprec-- + 1)
	{
		tmp = (intmax_t)(nb * 10);
		nb = nb * 10;
		if ((int)tmp == 0)
			tsize ++;
	}
	if ((f->size = ft_getsize((intmax_t)tmp, tFlags)) > 1)
	{
		while ((intmax_t)(tmp / 10) % 10 == 0 && (intmax_t)tmp % 10 == 0)
			tmp /= 10;
		f->size = ft_getsize((intmax_t) tmp, tFlags);
	}
	if (tsize > f->size && (intmax_t)tmp % 10 == 9)
	{
		f->add = 1;
		return (0);
	}
	f->size += tsize;
	return (f->size);
}

void 	ft_get_fal(t_float *f, long double nb, t_flags *tFlags)
{
	int i;

	nb *= 10;
	f->first = (intmax_t)nb;
	i = (int)f->size - 1;
	while (i-- > 0)
		nb *= 10;
	if ((intmax_t)nb % 10 == 9)
	{
		f->last = (intmax_t)nb % 10;
		while ((intmax_t)nb % 10 == 9 && (intmax_t)nb != 0)
			nb /= 10;
		f->first = ((intmax_t)nb % 10 == 0 ? (intmax_t)(nb / 10) % 10 : \
												(intmax_t)nb % 10);
	}
	else if (((intmax_t)nb % 10) == 5)
	{
		f->last = (intmax_t)nb % 10;
		if (f->type > 0)
		{
			if (f->size > 1)
				f->first = (intmax_t) (nb / 10) % 10;
			if (f->size > tFlags->prec)
				f->first = f->last;
		}
	}
	if (f->last == 0)
	{
		f->last = (intmax_t) nb % 10;
		if (f->first == 9 && f->last == 8 && !f->type)
			f->first = (intmax_t) (nb / 10) % 10;
	}
}

int		dec(t_float *f, int feven)
{
	if (f->type == LDEC && feven)
		return (1);
	if (!f->last)
		return (0);
	if (f->first == f->last)
		return (f->first >= 5 && f->size > 1 ? 1 : 0);
	if (f->last > 5)
		return (1);
	if (f->last == 5)
		return ((feven || f->first == 9) ? 1 : 0);
	if (f->last < 5)
		return (0);
	return (0);
}

int 	check_precision(t_float *f, t_flags *tFlags)
{
	long double		tmp;
	int 			feven;

	if (f->add)
		return (1);
	tmp = (f->nb < 0 ? -f->nb : f->nb);
	tmp -= (int)tmp;
	get_prec(f, tmp, tFlags);
	ft_get_fal(f, tmp, tFlags);
	if ((f->first % 2) == 0)
		feven = 1;
	if (!f->type)
	{
		if (tFlags->prec == 0 && f->first >= 5 && ((int)f->nb % 2) != 0)
			return (1);
		if (f->last == 9 && !f->first)
			return (1);
		if (f->first <= 5)
			return (0);
		if (f->first == 9)
			return (f->last == 8 || f->last == 9 ? 1 : 0);
	}
	else if (f->type > 0)
		return(dec(f, feven));
	return (0);
}

void	ft_check_str(char **str, int add) {
	int i;
	intmax_t nb;
	char *s;
	int mod;

	s = *str;
	i = (int) ft_strlen(&(**str)) - 1;
	if (add == 1) {
		while (s[i] == '9') {
			s[i] = '0';
			i--;
		}
		if (s[i] != '.') {
			nb = ft_atoi(&(s[i]));
			mod = (int) ft_modulo(nb, &add);
			nb = (nb / mod) + 1;
			s[i] = (char) (nb + '0');
		}
	}
}

void	ft_full_after(char **af, t_flags *tFlags, t_float *f)
{
	int j;
	int tmp;
	int i;
	int add;

	i = 0;
	tFlags->total += 1;
	j = 0;
	if (tFlags->prec > 0)
		(*af)[i++] = '.';
	add = check_precision(f, tFlags);
	while (j++ < tFlags->prec)
	{
		tmp = (intmax_t) (f->nb * 10);
		(*af)[i++] = (char) (tmp + '0');
		f->nb = f->nb * 10 - tmp;
	}
		ft_check_str(af, add);
}