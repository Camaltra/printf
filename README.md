# Printf function

## General

    Hello, and welcome to our first team project.
    You are in the project of Franck LEGER and Mickael BOILLAUD and in this project, 
    we write our own printf function.

## Requirements

    For compiling:

    > gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

    Ubuntu 20.04.

### Source code in this project

* main.h

        Contain the use struct and all prototype function.
        Also contain the usefull library to run without issues the
        program, and to make all the limits test.

* man_3_printf

        The manual page for our printf function. 

* _printf.c

        This is the main file for printf function. Taking a const char pointer 
        with variadic function.
        The function printf return an int of characters printed.

* string_function.c

        This is the file that contain the functions print all the 
        string specifers, as %c and %s.
        Contain the functions :
        print_char - Print a char.
        print_str - Print a str.
        print_percent - Print a %.
        reversed_string - Reverse a str, then print it.

* print_int.c

        This is the file that contain all the functions to print any int number.
        Contain the functions: 
        print_int - Print an int.
        print_short - Print a short.
        print_long - Print a long.

* print_ouxX.c

        This is the file that contain all the functions to print all bases.
        Contain the functions:
        print_u_number - Print an unsigned int.
        print_octal - Print a octal number.
        choice_hexax - Redictect to the function print_hexa, specify to 
        print the hexa in lowercase.
        choice_hexaX - Redictect to the function print_hexa, specify to 
        print the hexa in uppercase.
        print_hexa - Convert an unsigned int into hexa, the print it. 

* 1_advanced_function.c

        This is the file that contain the function for advenced use of printf.
        Contain the function : 
        print_binary - Print a binary number
        print_p - Convert an number into adress, then print it
        rot13_convert - Convert a str into the rot13 language, then print it
        print_S - Print a str, every ASCII char that are not a usual char are print
                as "\x" with its 2 bytes hexa conversion.
        print_2hexaX - Convert a number into 2 bytes hexa number.

* 2_primary_functions.c

        This is the file that contain all the basic function that the program
        need to run
        Contain the functions : 
        _putchar - Print a char
        _strlen - Return the value of the length of the str

* convert_base.c

        This is the file that contain all the function to convert number 
        into differents bases.
        Contain the functions :
        convert_binary - Convert a unsigned int into binary.
        convert_octal - Convert a unsigned int into octal.
        convert_hoctal - Convert a unsigned short int into octal.
        convert_loctal - Convert a unsigned long int into octal.

* int_long_function

        This file contain all the function to print the %l, that
        allow to print long int number.
        Contain the functions :
        print_lu_number - Print a unsigned long int.
        print_loctal - Print a octal number from an unsigned long int.
        choice_hexax_long - Redictect to the function print_hexa, specify to 
        print the hexa in lowercase.
        choice_hexaX_long - Redictect to the function print_hexa, specify to 
        print the hexa in uppercase.
        print_hexa_long - Convert an unsigned long int into hexa, the print it. 

* int_short_function

        This file contain all the function to print the %l, that
        allow to print long int number.
        Contain the functions :
        print_hu_number - Print a unsigned short int.
        print_hoctal - Print a octal number from an unsigned short int.
        choice_hexax_short - Redictect to the function print_hexa, specify to 
        print the hexa in lowercase.
        choice_hexaX_short - Redictect to the function print_hexa, specify to 
        print the hexa in uppercase.
        print_hexa_short - Convert an unsigned short int into hexa, the print it.
