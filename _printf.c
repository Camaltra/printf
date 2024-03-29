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

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(arg, format);

	for (i = 0; *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			if (*(format + i + 1) != '\0')
				print_func = get_print_func((format + i + 1));
			if (print_func != NULL)
			{
				sum += print_func(arg);
				if (*(format + i + 1) == 'l' || *(format + i + 1) == 'h')
					i += 2;
				else
					i++;
			}
			else
			{
				_putchar(*(format + i));
				sum++;
				if (*(format + i + 1) == 'l' || *(format + i + 1) == 'h')
					i++;
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
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"u", print_u_number},
		{"o", print_octal},
		{"x", choice_hexax},
		{"X", choice_hexaX},
		{"%", print_percent},
		{"S", print_S},
		{"r", reversed_string},
		{"R", rot13_convert},
		{"p", print_p},
		{NULL, NULL}
	};

	if (*format == 'l')
		return (get_l_func((format + 1)));

	if (*format == 'h')
		return (get_h_func((format + 1)));

	for (j = 0; p[j].conversion != NULL; j++)
		if (p[j].conversion != NULL && *p[j].conversion == *format)
			return (p[j].f);

	return (0);
}

/**
 * get_l_func - Function that select the right
 * function we need for the specifiers
 *
 * @format: The specifier we test for select function
 *
 * Return: Function in a array p
 * or 0 if no function is selected
 */
int (*get_l_func(const char *format))(va_list)
{
	int j;

	specifers p[] = {
		{"d", print_long},
		{"i", print_long},
		{"u", print_lu_number},
		{"o", print_loctal},
		{"x", choice_hexax_long},
		{"X", choice_hexaX_long},
		{NULL, NULL},
	};

	for (j = 0; p[j].conversion != NULL; j++)
		if (p[j].conversion != NULL && *p[j].conversion == *format)
			return (p[j].f);

	return (0);
}

/**
 * get_h_func - Function that select the right
 * function we need for the specifiers
 *
 * @format: The specifier we test for select function
 *
 * Return: Function in a array p
 * or 0 if no function is selected
 */
int (*get_h_func(const char *format))(va_list)
{
	int j;

	specifers p[] = {
		{"d", print_short},
		{"i", print_short},
		{"u", print_hu_number},
		{"o", print_hoctal},
		{"x", choice_hexax_short},
		{"X", choice_hexaX_short},
		{NULL, NULL},
	};

	for (j = 0; p[j].conversion != NULL; j++)
		if (p[j].conversion != NULL && *p[j].conversion == *format)
			return (p[j].f);

	return (0);
}
