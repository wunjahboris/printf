#include "main.h"

/**
* _printf - Receives the main string and all required parameters to output a formatted string
*@format: A string containig all the desired characters
*Return: A total count of the characters printed
*/
int _printf(const char *format, ...)
{
	int output_chars;
	mod_sf f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", rot13},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_hex},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	/*calling parser function*/
	output_chars = syntax_i(format, f_list, arg_list);
	va_end(arg_list);
	return (output_chars);
}
