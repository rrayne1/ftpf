#include "includes/ft_printf.h"
#define INT_MIN -2147483648
#define INT_MAX 2147483649
int 	main(void)
{
	int a = 0;
	int b = 0;
	//int a01, a02, a03, a04, a05, a06, a07, a08, a09, a10, a11, a12;

	a = printf("%f", -1.5);
	printf("\n");
	b = ft_printf("%f", -1.5);
	printf("\n %d %d \n", a, b);
	return (0);
}
