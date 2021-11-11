#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

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

int reversed_string(va_list arg);

int _printf(const char *format, ...);
int (*get_print_func(const char *format))(va_list);
int (*get_l_func(const char *format))(va_list);
int (*get_h_func(const char *format))(va_list);

int _pow_recursion(int x, int y);

int print_binary(va_list arg);
char *convert_binary(unsigned int number);
char *convert_octal(unsigned int number);

int print_u_number(va_list arg);
int print_octal(va_list arg);

int print_hexa(unsigned int number, int upper);
int choice_hexaX(va_list arg);
int choice_hexax(va_list arg);

int print_hexa_long(unsigned long int number, int upper);
int choice_hexaX_long(va_list arg);
int choice_hexax_long(va_list arg);

int print_hexa_short(unsigned short int number, int upper);
int choice_hexaX_short(va_list arg);
int choice_hexax_short(va_list arg);

int print_int(va_list arg);
int print_short(va_list arg);
int print_long(va_list arg);

int print_pourcent(va_list arg);

int print_percent(va_list arg __attribute__((unused)));

int print_S(va_list arg);
int print_2hexaX(char c);

int rot13_convert(va_list arg);

int print_p(va_list arg);

char *convert_loctal(unsigned long number);
int print_loctal(va_list arg);
int print_lu_number(va_list arg);

int print_hu_number(va_list arg);
int print_hoctal(va_list arg);
char *convert_hoctal(unsigned short number);

#endif
