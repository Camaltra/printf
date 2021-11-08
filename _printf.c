#include "main.h"

/**
 * _printf - This is our printf function
 * That print all format is possible
 *
 * @format: All arguments we want to print in the
 * same format
 *
 * Return: Upon sucessful return, the functions return the number of
 * charaters printed.
 */
int _printf(const char *format, ...)
{
	/* initialisation of index */
	int i, j, sum = 0;

	specifers p[] = {
		{'c', print_char},
		{'s', print_str},
		{'i', print_int},
		{'d', print_double},
		/*
		{'b', print_binary},
		{'u',},
		{'o', print_octal},
		{'x',},
		{'X',},
		{'S',},
		{'p', print_pointer},
		*/
		{NULL, NULL};
	};
	va_list arg;

	va_start(arg, format);

	for (i = 0; *(format + i); i++)
	{
		while (*(format + i) != '%')
		{
			_putchar(*(format + i));
			sum++;
			i++;
		}
		if (*(format + i) == '%')
		{
			i++;
			for (j = 0; *p[j].conversion; j++)
			{
				if (*p[j].conversion == *(format + i + 1))
				{
					sum += *p[j].f(arg);
					break;
				}
			}
		}
	}
	va_end(print);
	_putchar('\n');
	return (0);
}
