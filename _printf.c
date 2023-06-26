#include "main.h"

/**
 * _printf - prints output according to a format specifier.
 * @format: a pointer to the format string.
 * @...: variadic arguments corresponding to the format specifier.
 *
 * Return: the number of characters printed.
*/
int _printf(const char *format, ...)
{
	int count;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	count = iterate_format_s(format, args);

	va_end(args);
	return (count);
}

/**
 * iterate_format_s - iterates over the format string
 *                    and calls the appropriate functions.
 * @format: a pointer to the format string.
 * @args: the variable arguments list.
 *
 * Return: the number of characters printed.
*/
int iterate_format_s(const char *format, va_list args)
{
	int i, count = 0;
	format_t format_cases[] = {
		{'c', c_case}, {'s', s_case}, {'%', p_case},
		{'d', d_i_case}, {'i', d_i_case}, {'b', b_case},
		{'u', u_case}, {'o', o_case}, {'x', x_case},
		{'X', X_case}, {'S', S_case}, {'p', poin_case},
		{0, NULL}
	};

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			while (*format == ' ')
				format++;
			if (*format == '\0')
				return (-1);
			for (i = 0; format_cases[i].format_case; i++)
			{
				if (format_cases[i].format_case == *format)
				{
					count += format_cases[i].func(args);
					break;
				}
			}
			if (!format_cases[i].format_case)
			{
				count += handle_default('%');
				count += handle_default(*format);
			}
		} else
			count += handle_default(*format);
		format++;
	}

	return (count);
}

/**
 * handle_default - handles the default case when no specifier is found.
 * @character: the character to be printed.
 *
 * Return: the number of characters printed (1).
*/
int handle_default(const char character)
{
	write(1, &character, 1);
	return (1);
}
