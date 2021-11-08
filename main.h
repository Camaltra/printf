#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>

/* ----- Structure ----- */

/**
 * struct spe - List all conversion specifiers.
 *
 * @conversion: Character associated with a function
 * @f: Function to call, for print the variable
 *
 */
typedef struct spe
{
	char *conversion;
	int (*f)(va_list);
} specifers;

/* ----- Prototype of all functions ----- */

int _putchar(char c);

int print_char(va_list arg);

int print_str(va_list arg);

int _printf(const char *format, ...);

#endif
