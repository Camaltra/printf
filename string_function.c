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
	is_char = va_arg(arg, char);
	if (arg < 0 || arg > 127)
	{
		_printf("It is not a char");
		exit(1);
	}
	_putchar(arg);
	return (1);
}

/**
 * is_string - Test if it's a string, print it
 *
 * @arg: Given string
 *
 * Return: Length of the string
 */
int is_string(va_list arg)
{
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		_printf("It is not a str");
		exit(2);
	}
	_printf("%s", str);
	return (_strlen(str));
}
