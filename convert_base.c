#include "main.h"

/**
 * convert_binary - Allocate memory in a string
 * and do the convert of decimal to binary in the function
 *
 * @number: The unsigned int we want to convert
 *
 * Return: str;
 */
char *convert_binary(unsigned int number)
{
	char *str;
	int length = 0;
	unsigned int searchLength = number;

	while (searchLength >= 2)
	{
		searchLength /= 2;
		length++;
	}

	str = malloc(sizeof(char) * (length + 2));

	if (str == NULL)
		return (0);

	*(str + length + 1) = '\0';

	while (length >= 0)
	{
		str[length] = number % 2 + '0';
		number /= 2;
		length--;
	}

	return (str);
}

/**
 * convert_octal - Allocate memory in a string
 * and do the convert of decimal to octal in the function
 *
 * @number: The unsigned int we want to convert
 *
 * Return: str;
 */
char *convert_octal(unsigned int number)
{
	char *str;
	int length = 0;
	unsigned int searchLength = number;

	while (searchLength >= 8)
	{
		searchLength /= 8;
		length++;
	}

	str = malloc(sizeof(char) * (length + 2));

	if (str == NULL)
		return (0);

	*(str + length + 1) = '\0';

	while (length >= 0)
	{
		str[length] = number % 8 + '0';
		number /= 8;
		length--;
	}

	return (str);
}

/**
 * convert_hoctal - Allocate memory in a string
 * and do the convert of decimal to octal in the function
 *
 * @number: The unsigned short we want to convert
 *
 * Return: str;
 */
char *convert_hoctal(unsigned short number)
{
	char *str;
	int length = 0;
	unsigned short searchLength = number;

	while (searchLength >= 8)
	{
		searchLength /= 8;
		length++;
	}

	str = malloc(sizeof(char) * (length + 2));

	if (str == NULL)
		return (0);

	*(str + length + 1) = '\0';

	while (length >= 0)
	{
		str[length] = number % 8 + '0';
		number /= 8;
		length--;
	}

	return (str);
}

/**
 * convert_loctal - Allocate memory in a string
 * and do the convert of decimal to octal in the function
 *
 * @number: The unsigned long we want to convert
 *
 * Return: str;
 */
char *convert_loctal(unsigned long number)
{
	char *str;
	int length = 0;
	unsigned long searchLength = number;

	while (searchLength >= 8)
	{
		searchLength /= 8;
		length++;
	}

	str = malloc(sizeof(char) * (length + 2));

	if (str == NULL)
		return (0);

	*(str + length + 1) = '\0';

	while (length >= 0)
	{
		str[length] = number % 8 + '0';
		number /= 8;
		length--;
	}

	return (str);
}
