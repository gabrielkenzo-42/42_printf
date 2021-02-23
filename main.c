#include "ft_printf.h"
# include <stdio.h>

int main()
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	char	str[100] = "12345678910111213141516171819";

	//PRINT_N
	printf("PRINT_N:\n");
	a = ft_calloc(2, sizeof(int));
	b = ft_calloc(2, sizeof(int));
	size_a = printf("%s%nabcde\n", str, a);
	size_b = ft_printf("%s%nabcde\n", str, b);
	printf("\noriginal:\nreturn = %d\npointer = %d\n\n", size_a, *a);
	printf("my function:\nreturn = %d\npointer = %d\n", size_b, *b);
	printf("\n");
	printf("\n");

	//PRINT_E
	float	f;
	f = -0.0001495;
	f = 0.000000000000000000000000000000000000000000005;
	f = 1.234;
	f = -1.141595;

	printf("PRINT_E:\n");
	size_a = printf("%3f", f);
	printf(" return: %d\n", size_a);
	size_b = ft_printf("%3f", f);
	printf(" return: %d\n", size_b);
	printf("\n");
	printf("\n");

	//PRINT_F
	printf("PRINT_F:\n");
	size_a = printf("%e", f);
	printf(" return: %d\n", size_a);
	size_b = ft_printf("%e", f);
	printf(" return: %d\n", size_b);

	// //PRINT_G    NÃO FIZ ESSE
	// size_a = printf("%g", f);
	// printf(" return: %d\n", size_a);
	// size_b = ft_printf("%g", f);
	// printf(" return: %d\n", size_b);
	// return (0);
}
