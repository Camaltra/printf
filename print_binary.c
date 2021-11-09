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
	int length = 0, result = 0, pow = -1;
	unsigned int toconvert = va_arg(arg, unsigned int);

	while (toconvert != 0)
	{
		if (toconvert % 2 != 0)
		{
			result += 1 * _pow_recursion(10, length);

		}
		toconvert /= 2;
		length++;
		pow++;
	}

	while (pow >= 0)
	{
		_putchar((result / _pow_recursion(10, pow)) % 10 + '0');
		pow--;
	}

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
