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
	int size = 1, number, i;
	int n = va_arg(arg, int);

	while (n / size > 9 || n / size < -9)
		size *= 10;

	if (n < 0)
		_putchar('-');

	for (i = size; i >= 1; i /= 10)
	{
		if (n >= 0)
			number = (n / i) % 10;
		else
			number = ((n / i) % 10) * -1;

		_putchar(number + '0');
	}
	return (1);
}
