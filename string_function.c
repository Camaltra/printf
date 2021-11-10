#include "main.h"

/**
 * print_char - Test if it's a char, print it
 *
 * @arg: Char to print
 *
 * Return: 1, the lenght of a char
 */
int print_char(va_list arg)
{
	_putchar(va_arg(arg, int));
	return (1);
}

/**
 * print_str - Test if it's a string, print it
 *
 * @arg: Given string
 *
 * Return: Length of the string
 */
int print_str(va_list arg)
{
	char *str;
	int i;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}

/**
 * print_percent - Print the percent
 *
 * @arg: arg to print
 *
 * Return: 1 : Length of the %
 */
int print_percent(va_list arg __attribute__((unused)))
{
	return (_putchar('%'));
}

/**
 * reversed_string - Print a string in reverse
 *
 * @arg: The variadic variable with the string
 * we want to print
 *
 * Return: length of the reversed string
 */
int reversed_string(va_list arg)
{
	int length, start = 0, end;
	char *str = va_arg(arg, char *), *revStr;

	if (str == NULL)
		str = "(null)";

	length = _strlen(str);
	revStr = malloc(sizeof(char) * (length + 1));
	end = length - 1;

	if (revStr == NULL)
		return (0);

	while (start <= length)
	{
		revStr[start] = str[end];
		start++;
		end--;
	}

	_printf("%s", revStr);

	return (length);
}
