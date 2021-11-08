#include "main.h"

/**
 * print_u_number - Prints an unsigned integer
 *
 * @arg: unsigned int variable we print
 *
 * Return: The length that function have print
 */
int print_u_number(va_list arg)
{
	int size = 1, result, i, length = 0;
	unsigned int un_number = va_arg(arg, unsigned int);

	while (un_number / size > 9)
		size *= 10;

	for (i = size; i >= 1; i /= 10)
	{
		result = (un_number / i) % 10;
		_putchar(result + '0');
		length++;
	}

	return (length);
}

/**
 * print_octal - Convert a decimal to
 * octal and prints it
 *
 * @arg: The variadic variable with the int we
 * want to convert
 *
 * Return: length of the print
 */
int print_octal(va_list arg)
{
	int length = 0, i;
	unsigned long result = 0, last_digit, size = 1;
	unsigned int toconvert = va_arg(arg, unsigned int);

	while (toconvert != 0)
	{
		if (toconvert >= 8 && toconvert % 8 != 0)
			result += (toconvert % 8) * _pow_recursion(10, length);
		else if (toconvert < 8)
		{
			last_digit = toconvert;
			for (i = length; i > 0; i--)
			{
				last_digit *= 10;
				size *= 10;
			}
			result += last_digit;
		}
		toconvert /= 8;
		length++;
	}

	for (i = length; i > 0; i--)
	{
		_putchar((result / size) % 10 + '0');
		size /= 10;
	}

	return (length);
}