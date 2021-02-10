#include "ft_printf.h"
# include <stdio.h>

int main()
{
	int *i;

	i = ft_calloc(10, sizeof(int));
	printf("12345%n\n", i);
	printf("%d\n", *i);
	return (0);
}
