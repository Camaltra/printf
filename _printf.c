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
	va_list arg;

	clean_buffer(buffer);
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
			buffer_len = check_buffer(holder, buffer_len, 1, buffer);
		}
	}
	_print(buffer, buffer_len);
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

/**
* check_buffer - Check is the buffer is full, else print in
*
* @holder: Array of the elem to copy into the buffer
* @buffer_len: Length of the current buffer
* @holder_len: Length of the holder array
* @buffer: Current buffer
*
* Return the length of the current buffer
*/
void check_buffer(char *holder, unsigned int buffer_len, unsigned int holder_len, char *buffer)
{
	if (buffer_len + holder_len > BUFFER_SIZE)
	{
		_memcpy_end(buffer, holder, BUFFER_SIZE - buffer_len, buffer_len);
		_print(buffer, BUFFER_SIZE);
		clean_buffer(buffer);
		holder += (BUFFER_SIZE - buffer_len);
		_memcpy_end(buffer, holder, holder_len - (BUFFER_SIZE - buffer_len), 0);
		buffer_len = holder_len - (BUFFER_SIZE - buffer_len);
	}
	else
	{
		_memcpy_end(buffer, holder, holder_len, buffer_len)
		buffer_len += holder_len;
	}
	return (buffer_len);
}


/**
* clean_buffer - Clean the buffer, fill it with 0
*
* @buffer: The buffer to clean
*
* Return: Anything, cause void function
*/
void clean_buffer(buffer)
{
	int i;

	for(i = 0; i < BUFFER_SIZE; i++)
		buffer[i] = 0;
}

/**
* _memcpy_end - Fill the dest array, at the index start, with the src array, till n
*
* @dest: Destination array
* @src: Source array
* @n: Size to copy
* @start: Index to strat the copy
*
*/
void _memcpy_end(char *dest, char *src, unsigned int n, unsigned int start)
{
	int i;

	for(i = 0; i < n; i++)
		dest[start + i] = src[i]; 
}

void _print(char *buffer, unsigned int size)
{
	write(1, buffer, size);
}