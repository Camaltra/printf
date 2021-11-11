#include "main.h"

/**
 * print_lu_number - Prints an unsigned integer
 *
 * @arg: unsigned long variable we print
 *
 * Return: The length that function have print
 */
int print_lu_number(va_list arg)
{
	unsigned long size = 1, result, i, length = 0;
	unsigned long un_number = va_arg(arg, unsigned long);

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
 * print_loctal - Convert a decimal to
 * octal and prints it
 *
 * @arg: The variadic variable with the int we
 * want to convert
 *
 * Return: i is length of the print
 */
int print_loctal(va_list arg)
{
	int i = 0;
	unsigned long toconvert = va_arg(arg, unsigned long);
	char *result;

	if (toconvert == 0)
		return (_putchar('0'));

	result = convert_loctal(toconvert);

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
* choice_hexax_long - Print the unsigned long int into an hexa number
* in lowercase.
*
* @arg: The unsigned int to print
*
* Return: The length of the hexa number
*/
int choice_hexax_long(va_list arg)
{
	return (print_hexa_long(va_arg(arg, unsigned long int), 0));
}

/**
* choice_hexaX_long - Print the unsigned long int into an hexa number
* in uppercase.
*
* @arg: The unsigned int to print
*
* Return: The length of the hexa number
*/
int choice_hexaX_long(va_list arg)
{
	return (print_hexa_long(va_arg(arg, unsigned long int), 1));
}

/**
* print_hexa_long - Print the long hexa number
*
* @number: The unsigned int to print
* @upper: Choice is this will be an upper or lower hexa
*
* Return: The length of the hexa number
*/
int print_hexa_long(unsigned long int number, int upper)
{
	int i = 0, j, count = 0;
	unsigned long int diff;
	unsigned long int tmp;
	char hexa[17];

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
