#include "main.h"

/**
 * print_binary - Convert an int to binary
 * and print it
 *
 * @arg: The variadic variable we need to
 * convert and print it
 *
 * Return: loop it's the length of the print
 */
int print_binary(va_list arg)
{
	int length = 0, pow = 0, loop = 0;
	unsigned int toconvert = va_arg(arg, unsigned int), searchLength = toconvert;
	char result[31] = { '\0' };

	if (toconvert == 0)
	{
		_putchar('0');
		return (1);
	}
	while (searchLength >= 2)
	{
		searchLength /= 2;
		length++;
		pow++;
	}

	while (pow >= 0)
	{
		result[pow] = (toconvert % 2);
		pow--;
		toconvert /= 2;
	}

	for (loop = 0; loop <= length; loop++)
		_putchar(result[loop] + '0');

	return (length);
}

/**
 * _pow_recursion - Return the value of x raised to the power of y
 *
 * @x: The number we raised
 * @y: The exposant
 *
 * Return: -1 if y < 0, 1 if y == 0, the value of x^y
 */
int _pow_recursion(int x, int y)
{

	if (y > 0)
		return (x * _pow_recursion(x, y - 1));
	else
		return (1);
}
