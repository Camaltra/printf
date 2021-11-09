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
	int i, sum = 0;
	int (*print_func)(va_list);

	va_list arg;

	va_start(arg, format);

	for (i = 0; *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			if (*(format + i + 1) == *(format + i))
			{
				_putchar(*(format + i));
				i++;
				sum++;
			} else
			{
				i++;
				print_func = get_print_func((format + i));
				if (print_func != NULL)
					sum += print_func(arg);
				else
					return (0);
			}
		} else
		{
			_putchar(*(format + i));
			sum++;
		}
	}
	va_end(arg);
	return (sum);
}

/**
 * get_print_func - Function that select the right
 * function we need for the specifiers
 *
 * @format: The specifier we test for select function
 *
 * Return: Function in a array p
 * or 0 if no function is selected
 */
int (*get_print_func(const char *format))(va_list)
{
	int j;

	specifers p[] = {
		{"c", print_char},
		{"s", print_str},
		/*{"d", print_int},*/
		/*{"i", print_int},*/
		{"b", print_binary},
		{"u", print_u_number},
		{"o", print_octal},
		{"x", print_hexax},
		{"X", print_hexaX},
		{NULL, NULL}
	};

	for (j = 0; p[j].conversion != NULL; j++)
		if (p[j].conversion != NULL && *p[j].conversion == *format)
			return (p[j].f);

	return (0);
}
