#include "main.h"
#include <stdio.h>

/**
*rev_string - reverses a string
*
*@s: string to reverse
*Return: A pointer to a character
*/
char *rev_string(char *s)
{
	int len;
	int begn;
	char tmp;
	char *dest;

	for (len = 0; s[len] != '\0'; len++)
	{}

	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, len);
	for (begn = 0; begn < len; begn++, len--)
	{
		tmp = dest[len - 1];
		dest[len - 1] = dest[begn];
		dest[begn] = tmp;
	}
	return (dest);
}

/**
*put_base - sends characters to be written to standard output
*@str: String to interprete
*/
void put_base(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_pchar(str[i]);
}

/**
*base_len - calculates the length of an ocatal number
*@num: The number for which the length is being calculated
*@base: Base to be calculated by
*Return: An integer representing the length of a number
*/
unsigned int base_len(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num = num / base;
	}
	return (i);
}

/**
*_memcpy - copy memory area
*@@dest: Destination for copying
*@src: SOurce to copy from
*@n: The number of bytes to copy
*Return: The memcpy() function returns a pointer to dest
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
