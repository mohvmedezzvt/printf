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
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;
	int length = 0, i;
	char *str;

	while (temp != 0)
	{
		temp /= 10;
		length++;
	}

	str = (char *)malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (-1);

	for (i = length - 1; i >= 0; i--)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
	}
	str[length] = '\0';

	write(1, str, length);

	free(str);
	return (length);
}
