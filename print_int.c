#include "main.h"

/**
 * print_int - Print an int
 *
 * @arg: Int to print
 *
 * Return: Lenght of int
 */
int print_int(va_list arg)
{
	int i = 0;
	int num = va_arg(arg, int);

	if (num == 0)
	{
		_putchar('0');
		i++;
	}
	if (num < 0)
	{
		_putchar('-');
		i++;
		num *= -1;
	}
	while (num > 0)
	{
		_putchar(num % 10 + '0');
		num /= 10;
		i++;
	}
	return (i);
}
