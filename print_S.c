#include "main.h"

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
	int i, count = -1;

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
