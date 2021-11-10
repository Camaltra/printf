#include "main.h"
#include <stdio.h>

/**
* print_p - Print the pointer, as %p
*
* @arg: Pointer inputed
*
* Return: Length of the output
*/
int print_p(va_list arg)
{
	unsigned long int number = va_arg(arg, unsigned long int);
	unsigned long int tmp;
	int k, j, i = 2, count = 2;
	char addr[16];
	char *str;

	str = "(nil)";

	if (number == 0)
	{
		for (k = 0; k < 5; k++)
			_putchar(*(str + k));
		return (5);
	}
	_putchar('0');
	_putchar('x');
	while (number != 0)
	{
		tmp = number % 16;
		if (tmp >= 10)
			addr[i] = tmp + 39 + '0';
		else
			addr[i] = tmp + '0';
		number /= 16;
		i++;
		count++;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(addr[j]);
	return (count);
}
