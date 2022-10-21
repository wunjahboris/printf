#include "main.h"

/**
 * syntax_i - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @f_list: A list of all the posible functions.
 * @arg_list: A list containing all the argumentents passed to the program.
 * Return: A total count of the characters printed.
 */
int syntax_i(const char *format, mod_sf f_list[], va_list arg_list)
{
	int i, j, r_val, output_chars;

	output_chars = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			/*Iterates through struct to find the right func*/
			for (j = 0; f_list[j].sign != NULL; j++)
			{
				if (format[i + 1] == f_list[j].sign[0])
				{
					r_val = f_list[j].f(arg_list);
					if (r_val == -1)
						return (-1);
					output_chars += r_val;
					break;
				}
			}
			if (f_list[j].sign == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_pchar(format[i]);
					_pchar(format[i + 1]);
					output_chars = output_chars + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_pchar(format[i]); /*call the write function*/
			output_chars++;
		}
	}
	return (output_chars);
}


/**
 * run_printf - Reads through the format string for _printf.
 * @format: Character string to print - may contain directives.
 * @output: A buffer_t struct containing a buffer.
 * @args: A va_list of arguments.
 *
 * Return: The number of characters stored to output.
 */
int run_printf(const char *format, va_list args, buffer_t *output)
{
	int i, wid, prec, ret = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		len = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
			flags = handle_flags(format + i + 1, &tmp);
			wid = handle_width(args, format + i + tmp + 1, &tmp);
			prec = handle_precision(args, format + i + tmp + 1,
					&tmp);
			len = handle_length(format + i + tmp + 1, &tmp);

			f = handle_specifiers(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				ret += f(args, output, flags, wid, prec, len);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memcpy(output, (format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	return (ret)}
