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
	int size = 1, number, i, length = 0;
	int n = va_arg(arg, int);

	while (n / size > 9 || n / size < -9)
		size *= 10;

	if (n < 0)
		length += _putchar('-');

	for (i = size; i >= 1; i /= 10, length++)
	{
		if (n >= 0)
			number = (n / i) % 10;
		else
			number = ((n / i) % 10) * -1;

		_putchar(number + '0');
	}
	return (length);
}

/**
 * print_short - Print a short int
 *
 * @arg: Int to print
 *
 * Return: Lenght of int
 */
int print_short(va_list arg)
{
	short int size = 1, number, i, length = 0;
	short int n = va_arg(arg, short int);

	while (n / size > 9 || n / size < -9)
		size *= 10;

	if (n < 0)
		length += _putchar('-');

	for (i = size; i >= 1; i /= 10, length++)
	{
		if (n >= 0)
			number = (n / i) % 10;
		else
			number = ((n / i) % 10) * -1;

		_putchar(number + '0');
	}
	return (length);
}

/**
 * print_long - Print a long int
 *
 * @arg: Int to print
 *
 * Return: Lenght of int
 */
int print_long(va_list arg)
{
	long int size = 1, number, i, length = 0;
	long int n = va_arg(arg, long int);

	while (n / size > 9 || n / size < -9)
		size *= 10;

	if (n < 0)
		length += _putchar('-');

	for (i = size; i >= 1; i /= 10, length++)
	{
		if (n >= 0)
			number = (n / i) % 10;
		else
			number = ((n / i) % 10) * -1;

		_putchar(number + '0');
	}
	return (length);
}
