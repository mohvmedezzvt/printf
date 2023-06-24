#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/* functions in _printf.c file */
int _printf(const char *format, ...);
int iterate_format_s(const char *format, va_list args);
int handle_default(const char character);

/* functions in 0_func.c */
int c_case(va_list args);
int s_case(va_list args);
int p_case(va_list args);
int d_i_case(va_list args);

/**
 * struct format_struct - represents a format specifier
 *                        and its corresponding function.
 *
 * @format_case: the format specifier character.
 * @func: a function pointer to the corresponding function
 *        for the format specifier.
 */
typedef struct format_struct
{
	char format_case;
	int (*func)(va_list args);
} format_t;

#endif /* MAIN_H */
