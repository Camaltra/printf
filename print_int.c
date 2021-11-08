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
	int number = va_arg(arg, int);
	int i = 0;

	if (number < 0)
		_putchar('-');
		i++;
	while (number != 0)
	{
		_putchar(number % 10);
		number /= 10;
		i++;
	}
	return (i);
}
