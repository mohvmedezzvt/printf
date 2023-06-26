#include "main.h"

/**
 * S_case - handles the conversion specifier '%S' for printf.
 * @args: the va_list containing the arguments.
 * Return: the number of characters written to the output.
 */
int S_case(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			count += handle_default('\\');
			count += handle_default('x');
			if (*str < 16)
				handle_default('0');
			count += X_case_aux(*str);
		}
		else
			count += handle_default(*str);
		str++;
	}

	return (count);
}

/**
 * X_case_aux - helper function for converting a character to
 *              hexadecimal format.
 * @c: the character to convert.
 *
 * Return: the number of characters printed.
 */
int X_case_aux(char c)
{
	int digit, count = 0, i;
	char hexa[] = "0123456789ABCDEF";
	char str[9];

	while (c != 0)
	{
		digit = c % 16;
		str[count] = hexa[digit];
		count++;
		c /= 16;
	}

	if (count == 0)
		count += handle_default('0');
	if (count == 1)
		count += handle_default(str[0]);
	else
	{
		for (i = count - 1; i >= 0; i--)
			handle_default(str[i]);
	}
	return (count);
}

/**
 * r_case - handles the 'r' conversion specifier,
 *          prints the reversed string.
 * @args: the va_list containing the string argument.
 *
 * Return: the number of characters printed.
 */
int r_case(va_list args)
{
	char *str = va_arg(args, char *);
	int length = 0, count = 0, i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	while (str[length] != '\0')
		length++;

	for (i = length - 1; i >= 0; i--)
		count += handle_default(str[i]);

	return (count);
}

/**
 * R_case - handles the 'R' conversion specifier,
 *          prints the ROT13'ed string.
 * @args: the va_list containing the string argument.
 *
 * Return: the number of characters printed.
 */
int R_case(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0, i;
	char c;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	for (i = 0; str[i]; i++)
	{
		c = str[i];
		if (c >= 'A' && c <= 'Z')
			c = 'A' + (c - 'A' + 13) % 26;
		else if (c >= 'a' && c <= 'z')
			c = 'a' + (c - 'a' + 13) % 26;

		count += handle_default(c);
	}

	return (count);
}
