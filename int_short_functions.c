#include "main.h"

/**
 * print_hu_number - Prints an unsigned integer
 *
 * @arg: unsigned short variable we print
 *
 * Return: The length that function have print
 */
int print_hu_number(va_list arg)
{
	unsigned short size = 1, result, i, length = 0;
	unsigned short un_number = va_arg(arg, int);

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
 * print_hoctal - Convert a decimal to
 * octal and prints it
 *
 * @arg: The variadic variable with the int we
 * want to convert
 *
 * Return: i is length of the print
 */
int print_hoctal(va_list arg)
{
	int i = 0;
	unsigned short toconvert = va_arg(arg, int);
	char *result;

	if (toconvert == 0)
		return (_putchar('0'));

	result = convert_hoctal(toconvert);

	if (result == NULL)
		return (0);

	while (result[i] != '\0')
	{
		_putchar(result[i]);
		i++;
	}

	free(result);

	return (i);
}

/**
* choice_hexax_short - Print the unsigned short int into an hexa number
* in lowercase.
*
* @arg: The unsigned int to print
*
* Return: The length of the hexa number
*/
int choice_hexax_short(va_list arg)
{
	return (print_hexa_short(va_arg(arg, unsigned int), 0));
}

/**
* choice_hexaX_short - Print the unsigned short int into an hexa number
* in uppercase.
*
* @arg: The unsigned int to print
*
* Return: The length of the hexa number
*/
int choice_hexaX_short(va_list arg)
{
	return (print_hexa_short(va_arg(arg, unsigned int), 1));
}

/**
* print_hexa_short - Print the short hexa number
*
* @number: The unsigned int to print
* @upper: Choice is this will be an upper or lower hexa
*
* Return: The length of the hexa number
*/
int print_hexa_short(unsigned short int number, int upper)
{
	int i = 0, j, count = 0;
	unsigned short int diff;
	unsigned short int tmp;
	char hexa[4];

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
