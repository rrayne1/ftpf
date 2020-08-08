#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include "../libft/libft.h"

#define TYPE_H 1
#define TYPE_HH 2
#define TYPE_L 3
#define TYPE_LL 4
#define TYPE_LF 5
#define p 6
#define DEC 1
#define LDEC 2

typedef struct 		s_flags
{
	int				count;
	int				width;
	char			space;
	char 			plus;
	char 			minus;
	char 			hash;
	char 			zero;
	int 			type;
	int 			prec;
	int 			neg;
	int 			total;
	int 			tmp;
}					t_flags;

typedef struct 		s_float
{
	long double		nb;
	long double		mod;
	intmax_t		first;
	intmax_t 		last;
	intmax_t 		size;
	int 			type;
	int 			add;
	int 			negz;
}					t_float;

int					ft_printf(const char *format, ...);
int 				start(va_list ft_printf_list, char **format);

void 				init_flags(t_flags *tFlags);
void				check_flags(char **format, t_flags *tFlags);
void 				check_types(char **format, t_flags *tFlags);
void				check_format(va_list ft_printf_list, char **format, \
									t_flags *tFlags);

int					type_s(va_list ft_print_list, t_flags *tFlags);
int 				type_c(va_list ft_printf_list, t_flags *tFlags);
int 				type_d(va_list ft_printf_list, t_flags *tFlags);
int 				type_f(va_list ft_printf_list, t_flags *tFlags);
int					type_o(va_list ft_print_list, t_flags *tFlags);
int					type_u(va_list ft_printf_list, t_flags *tFlags);
int					type_x(va_list ft_printf_list, t_flags *tFlags, char *base);
int					type_p(va_list ft_printf_list, t_flags *tFlags, char *base);

void				ft_get_nb_u(va_list ft_printf_list, uintmax_t *nb, \
									t_flags *tFlags);
void 				ft_get_nb(va_list ft_printf_list, intmax_t *nb, \
									t_flags *tFlags);

int					ft_getsize(intmax_t n, t_flags *tFlags);
void				ft_get_size_u(uintmax_t nb, uintmax_t length, int *size);
void 				ft_putnbr_base(uintmax_t nb, char *str, uintmax_t length);
void 				ft_precision(t_flags *tFlags, int size);
int 				check_zero(uintmax_t nb, int *size, t_flags *tFlags);

int					ft_infinity(t_float *f, t_flags *tFlags);
double				ft_modulo(long double nb, int *size);
int					ft_full(t_float *tFloat, t_flags *tFlags);
void 				ft_full_after(char **af, t_flags *tFlags, t_float *tFloat);
int 				check_precision(t_float *tFloat, t_flags *tFlags);

void				ft_print_width(t_flags *tFlags);
void 				ft_print_sign(t_flags *tFlags);
int   				ft_print_percent(t_flags *tFlags);
int 				ft_print_str(char **format);

void				ft_display_f(char *nb, t_flags *tFlags);
void 				ft_display_d(intmax_t nb, int size, t_flags *tFlags);
void 				ft_display_o(uintmax_t nb, int size, t_flags *tFlags);
void			 	ft_display_u(uintmax_t nb, int size, t_flags *tFlags);
void				ft_display_x(uintmax_t nb, int *size, t_flags *tFlags, \
									char *base);

int 				ft_write(void *s, int size);
void 				ft_write_char(char c, int size);

void 				total_str(char *s, size_t *len, t_flags *tFlags);
void				total_dit(intmax_t nb, int size, t_flags *tFlags);

#endif
