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
	int i;
	unsigned int buffer_len, holder_len;
	int (*print_func)(va_list);
	char buffer[BUFFER_SIZE], *holder;
	for (i = 0; i < BUFFER_SIZE; i++)
		*(buffer + i) = 0
	va_list arg;
	va_start(arg, format);

	for (i = buffer_len = holder_len = 0; format && *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			print_func = get_print_func(format + i);
			holder = print_func(arg);
			i++;
			holder_len = _strlen(holder)
			buffer_len = check_buffer(holder, buffer_len, holder_len, buffer);
		}
		else
		{
			holder = *(format + i)
			check_buffer(holder, buffer_len, 1, buffer);
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
		{"x", print_hexax},
		{"X", print_hexaX},
		{NULL, NULL}
	};

	for (j = 0; *p[j].conversion; j++)
		if (*p[j].conversion == *format && *p[j].conversion != '\0')
			return (p[j].f);

	return (0);
}
