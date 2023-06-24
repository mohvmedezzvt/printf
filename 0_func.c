#include "main.h"
/**
 * c_case - detects the formater c
 * @args: the value should be printed
 * Return: 1
 */
int c_case(va_list args)
{
	char c = (char)va_arg(args, int);

	write(1, &c, 1);
	return (1);
}
/**
 * s_case - detects the formater s
 * @args: the value should be printed
 * Return: 1
 */
int s_case(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
		str = "(null)";
	count += write(1, str, strlen(str));
	return (count);
}
/**
 * p_case - detects the formater p
 * @args: the value should be printed
 * Return: 1
 */
int p_case(va_list args)
{
	char c = '%';

	(void)args;
	write(1, &c, 1);
	return (1);
}
/**
 * d_i_case - detects the formater d
 * @args: the value should be printed
 * Return: count of the number of digits + 1 if negative
 */
int d_i_case(va_list args)
{
	int num = va_arg(args, int);
	int count = 0, i, is_negative = 0;
	int digits[10], num_digits = 0;

	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		count++;
		is_negative = 1;
	}

	if (num == 0)
	{
		count += handle_default('0');
		return (count);
	}

	while (num > 0)
	{
		digits[num_digits] = num % 10;
		num /= 10;
		num_digits++;
	}

	for (i = num_digits - 1; i >= 0; i--)
	{
		count += handle_default(digits[i] + '0');
	}

	return (count + is_negative);
}
