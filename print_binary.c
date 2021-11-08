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
	int loop = 0, result = 0;
	unsigned int toconvert = va_arg(arg, unsigned int);

	print_number(toconvert);
	while (toconvert != 0)
	{
		if (toconvert % 2 != 0)
		{
			result += 1 * _pow_recursion(10, loop);
		}
		toconvert /= 2;
		loop++;
	}

	print_number(result);

	return (loop);
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
