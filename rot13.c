#include "main.h"

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
