#include "ft_printf.h"
# include <stdio.h>

int main()
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	char	str[100] = "12345678910111213141516171819";

	//PRINT_N
	a = ft_calloc(2, sizeof(int));
	b = ft_calloc(2, sizeof(int));
	size_a = printf("%s%nabcde\n", str, a);
	size_b = ft_printf("%s%nabcde\n", str, b);
	printf("\n\noriginal:\nreturn = %d\npointer = %d\n\n", size_a, *a);
	printf("my function:\nreturn = %d\npointer = %d\n", size_b, *b);
	return (0);
}
