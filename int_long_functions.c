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
 * convert_loctal - Allocate memory in a string
 * and do the convert of decimal to octal in the function
 *
 * @number: The unsigned long we want to convert
 *
 * Return: str;
 */
char *convert_loctal(unsigned long number)
{
	char *str;
	int length = 0;
	unsigned long searchLength = number;

	while (searchLength >= 8)
	{
		searchLength /= 8;
		length++;
	}

	str = malloc(sizeof(char) * (length + 2));

	if (str == NULL)
		return (0);

	*(str + length + 1) = '\0';

	while (length >= 0)
	{
		str[length] = number % 8 + '0';
		number /= 8;
		length--;
	}

	return (str);
}
