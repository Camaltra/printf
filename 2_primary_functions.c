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
	return (write(1, &c, 1));
}

/**
 * _strlen - Return the length of a string
 *
 * @s: The String we want to know the length
 *
 * Return: length
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		s++;
		length++;
	}

	return (length);
}
