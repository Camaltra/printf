#include "main.h"

/**
 * print_binary - Convert an int to binary
 * and print it
 *
 * @arg: The variadic variable we need to
 * convert and print it
 *
 * Return: loop it's the length of the print
 */
int print_binary(va_list arg)
{
	int loop = 0;
	unsigned int toconvert = va_arg(arg, unsigned int);
	char *result;

	if (!toconvert)
		return (_putchar('0'));

	result = convert_binary(toconvert);

	if (result == NULL)
		return (0);

	while (result[loop] != '\0')
	{
		_putchar(result[loop]);
		loop++;
	}

	free(result);

	return (loop);
}

/**
* print_p - Print the pointer, as %p
*
* @arg: Pointer inputed
*
* Return: Length of the output
*/
int print_p(va_list arg)
{
	void *p = va_arg(arg, void *);
	uintptr_t x = (uintptr_t)p;
	char buffer[2 + sizeof(x) * 2];
	unsigned long int i, count = 0;
	char *str = "(nil)";

	if (p == 0)
	{
		for (i  = 0; i < 5; i++)
			count += _putchar(*(str + i));
		return (count);
	}
	buffer[0] = '0';
	buffer[1] = 'x';
	for (i = 0; i < sizeof(x) * 2; i++)
	{
		buffer[i + 2] = "0123456789abcdef"
		[(x >> ((sizeof(x) * 2 - 1 - i) * 4)) & 0xf];
	}
	for (i = 0; i < sizeof(buffer); i++)
	{
		if (i == 2)
		{
			for (i = 2; *(buffer + i) == '0'; i++)
				;
		}
		count += _putchar(*(buffer + i));
	}
	return (count);
}

/**
 * rot13_convert - Convert a string into rot13
 *
 * @arg: The variadic argument with the string
 *
 * Return: length
 */
int rot13_convert(va_list arg)
{
	int i;
	char *st = va_arg(arg, char *);

	if (st == NULL)
		st = "(null)";

	for (i = 0; st[i] != '\0'; i++)
		if ((st[i] >= 'a' && st[i] <= 'm') || (st[i] >= 'A' && st[i] <= 'M'))
			_putchar(st[i] + 13);
		else if ((st[i] >= 'n' && st[i] <= 'z') || (st[i] >= 'N' && st[i] <= 'Z'))
			_putchar(st[i] - 13);
		else
			_putchar(st[i]);

	return (i);
}

/**
* print_S - Print a \x and the hexa conversion of
* any char outside of the range (32 - 126) in ASCII.
* Else, print the char as usual.
*
* @arg: Str to print
*
* Return: The length of the output.
*/
int print_S(va_list arg)
{
	char *str;
	int i, count = 0;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";

	for (i = 0; *(str + i); i++)
	{
		if (*(str + i) < 32 || *(str + i) >= 127)
		{
			_putchar('\\'), _putchar('x'), count += 2;
			count += print_2hexaX(*(str + i));
		}
		else
		{
			_putchar(*(str + i));
			count++;
		}
	}
	return (count);
}

/**
* print_2hexaX - Print the ASCII char into a 2 char long
* hexa.
*
* @c: Char to convert and print in hexa.
*
* Return: Length of the output.
*/
int print_2hexaX(char c)
{
	char hexa[2];
	int tmp;
	int i = 0, j, count = 0;

	while (c != 0)
	{
		tmp = c % 16;
		if (tmp >= 10)
			hexa[i] = tmp + 7 + '0';
		else
			hexa[i] = tmp + '0';
		c /= 16;
		i++;
		count++;
	}
	if (count == 1)
		_putchar('0'), count++;
	for (j = i - 1; j >= 0; j--)
		_putchar(hexa[j]);
	return (count);
}
