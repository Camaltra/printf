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
 * convert_hoctal - Allocate memory in a string
 * and do the convert of decimal to octal in the function
 *
 * @number: The unsigned short we want to convert
 *
 * Return: str;
 */
char *convert_hoctal(unsigned short number)
{
	char *str;
	int length = 0;
	unsigned short searchLength = number;

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
