#include "main.h"

/**
 * u_case - converts an unsigned integer to a string representation
 *          and writes it to stdo.
 * @args: the va_list containing the unsigned integer argument.
 *
 * Return: the number of characters written, or -1 if an error occurred.
 */
int u_case(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int temp = n;
	int count = 0, i;
	char *str;

	if (n == 0)
		return (handle_default('0'));

	while (temp != 0)
	{
		temp /= 10;
		count++;
	}

	str = (char *)malloc((count + 1) * sizeof(char));
	if (str == NULL)
		return (-1);

	for (i = count - 1; i >= 0; i--)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	str[count] = '\0';

	write(1, str, count);

	free(str);
	return (count);
}

/**
 * o_case - convert and print an unsigned int argument as an octal number.
 * @args: a va_list arguments.
 *
 * Return: the number of characters printed.
 */
int o_case(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int digit, count = 0, i = 0;
	char octal[22];

	if (n == 0)
		return (handle_default('0'));

	while (n != 0)
	{
		digit = n % 8;
		octal[i++] = digit + '0';
		n /= 8;
	}

	while (i > 0)
		count += handle_default(octal[--i]);

	return (count);
}

/**
 * x_case - handles the conversion specifier '%x' for printf.
 * @args: the va_list containing the arguments.
 *
 * Return: the number of characters written to the output.
 */
int x_case(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int digit, count = 0, i;
	char hexa[] = "0123456789abcdef";
	char str[9];

	if (n == 0)
		return (handle_default('0'));

	while (n != 0)
	{
		digit = n % 16;
		str[count++] = hexa[digit];
		n /= 16;
	}

	for (i = count - 1; i >= 0; i--)
		handle_default(str[i]);

	return (count);
}

/**
 * X_case - handles the conversion specifier '%X' for printf.
 * @args: The va_list containing the arguments.
 *
 * Return: the number of characters written to the output.
 */
int X_case(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int digit, count = 0, i;
	char hexa[] = "0123456789ABCDEF";
	char str[9];

	if (n == 0)
		return (handle_default('0'));

	while (n != 0)
	{
		digit = n % 16;
		str[count++] = hexa[digit];
		n /= 16;
	}

	for (i = count - 1; i >= 0; i--)
		handle_default(str[i]);

	return (count);
}

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
		return (handle_default('(') + handle_default('n') +
				handle_default('u') + handle_default('l') +
				handle_default('l') + handle_default(')'));
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
