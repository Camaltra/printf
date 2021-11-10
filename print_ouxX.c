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

/**
* choice_hexax - Print the unsigned int into an hexa number
* in lowercase.
*
* @arg: The unsigned int to print
*
* Return: The length of the hexa number
*/
int choice_hexax(va_list arg)
{
	return (print_hexa(va_arg(arg, unsigned int), 0));
}

/**
* choice_hexaX - Print the unsigned int into an hexa number
* in uppercase.
*
* @arg: The unsigned int to print
*
* Return: The length of the hexa number
*/
int choice_hexaX(va_list arg)
{
	return (print_hexa(va_arg(arg, unsigned int), 1));
}


/**
* print_hexa - Print the hexa number
*
* @number: The unsigned int to print
* @upper: Choice is this will be an upper or lower hexa
*
* Return: The length of the hexa number
*/
int print_hexa(unsigned int number, int upper)
{
	int i = 0, j, count = 0;
	unsigned int diff;
	unsigned int tmp;
	char hexa[9];

	if (upper)
		diff = 'A' - ':';
	else
		diff = 'a' - ':';
	if (number == 0)
	{
		_putchar('0');
		return (1);
	}
	while (number != 0)
	{
		tmp = number % 16;
		if (tmp >= 10)
			hexa[i] = tmp + diff + '0';
		else
			hexa[i] = tmp + '0';
		number /= 16;
		i++;
		count++;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(hexa[j]);
	return (count);

}
