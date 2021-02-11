#include "ft_printf.h"
# include <stdio.h>

int		number_of_digits(float n)
{
	int ndigit;

	ndigit = 0;
	while (n > 1)
	{
		printf("n = %f\n", n);
		n /= 10;
		ndigit++;
	}
	return (ndigit);
}

char	*ftoa(float n)
{
	int		neg;
	int		digits;
	char	*str;

	neg = 0;
	if (n < 0)
		neg = 1;
	digits = number_of_digits(n);
	printf("number of digits: %d\n", digits);
	str = calloc(digits + neg + 2, sizeof(char));
// 	while (n != 0)
// 	{
// 		n
// 	}
	return (str);
}

int main()
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	char	str[100] = "12345678910111213141516171819";

	// //PRINT_N
	// a = ft_calloc(2, sizeof(int));
	// b = ft_calloc(2, sizeof(int));
	// size_a = printf("%s%nabcde\n", str, a);
	// size_b = ft_printf("%s%nabcde\n", str, b);
	// printf("\n\noriginal:\nreturn = %d\npointer = %d\n\n", size_a, *a);
	// printf("my function:\nreturn = %d\npointer = %d\n", size_b, *b);

	//PRINT_E
	float	f;

	//verificar arredondamentos
	//testar com digito 5
	f = 3.1495;
	f = 123;
	// size_a = printf("%3.2e", f);
	// printf(" return: %d\n", size_a);
	// //size_b = ft_printf("%3.2e", f);
	// //printf(" return: %d\n", size_b);

	// printf("\n");
	// size_a = printf("%3.2f", f);
	// printf(" return: %d\n", size_a);
	// //size_b = ft_printf("%3.2f", f);
	// //printf(" return: %d\n", size_b);

	ftoa(f);
	ft_printf("%d", 12);
	//printf("%f\n", f/10);
	return (0);
}
