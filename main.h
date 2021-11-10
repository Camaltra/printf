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
int _strlen(char *s);

int print_char(va_list arg);

int print_str(va_list arg);

int _printf(const char *format, ...);
int (*get_print_func(const char *format))(va_list);

int _pow_recursion(int x, int y);

int print_binary(va_list arg);
char *convert_binary(unsigned int number);

int print_u_number(va_list arg);
int print_octal(va_list arg);
int print_hexa(unsigned int number, int upper);
int choice_hexaX(va_list arg);
int choice_hexax(va_list arg);

int print_int(va_list arg);

int print_pourcent(va_list arg);

int print_percent(va_list arg __attribute__((unused)));

<<<<<<< HEAD
int rot13_convert(va_list arg);
=======

>>>>>>> 77a184394a0176f3d4aa0034ed5cad32d2bef81f

#endif
