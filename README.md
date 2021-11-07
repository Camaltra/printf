# Printf function

## General

    Hello, and welcome to our first team project.
    You are in the project of Franck LEGER and Mickael BOILLAUD and in this project, we write our own printf function.

## Requirements

    For compiling:

    > gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

    Ubuntu 20.04.

### Source code in this project

    * _printf.c

        This is the main file for printf function. Taking a const char pointer with variadic function.
        The function printf return an int of characters printed.

    * _putchar.c

        This is the file for the putchar function. We use a syscall write to output a character.

    * _strlen.c

        This is the file for the strlen fuction. We use this function to have the length of a string.

    * main.h

        This is the header file. We define here a structure spe for the specifiers and we define all prototype
        of functions we use for printf.

    * man_3_printf

        The manual page for our printf function. 
