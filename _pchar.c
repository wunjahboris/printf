#include "main.h"

/**
*_pchar - writes the character c to stdout
*@c: The character to print
*
*Return: On success 1.
*On error, -1 is returned
*/
int _pchar(char c)
{
	return (write(1, &c, 1));
}
