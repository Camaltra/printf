#include "main.h"

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
			i += 4;
		count += _putchar(*(buffer + i));
	}
	return (count);
}
