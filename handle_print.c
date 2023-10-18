#include "main.h"
/**
 * print_with_format - Print an argument based on its type and format.
 * @fmt: The formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: An index.
 * @buffer: An array for handling printing.
 * @flags: Flags indicating special formatting.
 * @width: The width for formatting.
 * @precision: The precision specification.
 * @size: The size specifier.
 *
 * Return: 1 if successful, 2 if there was an issue.
 */
int print_with_format(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, Unknowlen = 0, iPrintedChars = -1;
	fmt_t fmt_types[] = {
		{'c', p_char}, {'s', p_string}, {'%', p_percent},
		{'i', p_int}, {'d', p_int}, {'b', p_binary},
		{'u', p_unsigned}, {'o', p_octal}, {'x', p_hexadecimal},
		{'X', p_hexa_upper}, {'p', p_pointer}, {'S', p_non_printable},
		{'r', p_reverse}, {'R', p_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		Unknowlen += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			Unknowlen += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		Unknowlen += write(1, &fmt[*ind], 1);
		return (Unknowlen);
	}
	return (iPrintedChars);
}