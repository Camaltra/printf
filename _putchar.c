#include <unistd.h>

/**
 * _putchar - Print the character in parameter
 *
 * @c: The character we want to print
 *
 * Return: 1 if it works
 * -1 if we have an error
 */
int _putchar(char c)
{
	return(write(1, &c, 1));
}
