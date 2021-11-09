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
	char is_char;
	char str[1];

	is_char = va_arg(arg, int);
	if (is_char < 0 && is_char > 126)
	{
		_printf("It is not a char\n");
		exit(1);
	}
	str[0] = is_char;

	return (str);
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
	{
		_printf("It is not a str\n");
		exit(2);
	}
	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}
