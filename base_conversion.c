#include "main.h"
#include <stdio.h>
int hex_check(int, char);

/**
 * print_binary - Converts a number from base decimal to binary
 * @list: List of arguments passed to this function
 * Return: The length of the number printed
 */
int print_binary(va_list list)
{
	unsigned int num;
	int i, len;
	char *str;
	char *rev_str;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_pchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		num = num / 2;
	}
	str[i] = '\0';
	rev_str = rev_string(str);
	if (rev_str == NULL)
		return (-1);
	put_base(rev_str);
	free(str);
	free(rev_str);
	return (len);
}

/**
 * print_octal - Prints decimal numbers in octal
 * @list: List of all the arguments passed to the program
 * Return: Number of symbols printed to stdout
 */
int print_octal(va_list list)
{
	unsigned int num;
	int len;
	char *oct_n;
	char *rev_str;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_pchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 8);

	oct_n = malloc(sizeof(char) * len + 1);
	if (oct_n == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		oct_n[len] = (num % 8) + 48;
		num = num / 8;

	}
	oct_n[len] = '\0';
	rev_str = rev_string(oct_n);
	if (rev_str == NULL)
		return (-1);

	put_base(rev_str);
	free(oct_n);
	free(rev_str);
	return (len);
}

/**
 * print_hex - Prints a decimal in hexadecimal
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_hex(va_list list)
{
	unsigned int num;
	int len;
	int remn;
	char *hex_n;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_pchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	hex_n = malloc(sizeof(char) * len + 1);
	if (hex_n == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		remn = num % 16;
		if (remn > 9)
		{
			remn = hex_check(remn, 'x');
			hex_n[len] = remn;
		}
		else
			hex_n[len] = remn + 48;
		num = num / 16;
	}
	hex_n[len] = '\0';
	rev_hex = rev_string(hex_n);
	if (rev_hex == NULL)
		return (-1);
	put_base(rev_hex);
	free(hex_n);
	free(rev_hex);
	return (len);
}


/**
 * print_heX - Prints a representation of a decimal number on base16 Uppercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_heX(va_list list)
{
	unsigned int num;
	int len;
	int remn;
	char *hex_n;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_pchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	hex_n = malloc(sizeof(char) * len + 1);
	if (hex_n == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		remn = num % 16;
		if (remn > 9)
		{
			remn = hex_check(remn, 'X');
			hex_n[len] = remn;
		}
		else
			hex_n[len] = remn + 48;
		num = num / 16;
	}
	hex_n[len] = '\0';
	rev_hex = rev_string(hex_n);
	if (rev_hex == NULL)
		return (-1);
	put_base(rev_hex);
	free(hex_n);
	free(rev_hex);
	return (len);
}

/**
 * hex_check - Checks which hex function is calling it
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}
