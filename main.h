#ifndef MAIN_H
#define MAIN_H

/* ----- Structure ----- */

/**
 * struct spe - List all conversion specifiers.
 *
 * @specifers: Conversion specifiers
 * @f: Function to call, for print the variable
 *
 */
typedef struct spe
{
	char specifers;
	int (*f)(va_list);
} specifers;

/* ----- Prototype of all function ----- */

int _putchar(char c);

#endif
