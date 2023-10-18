#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
int print_unknown_format(char buffer[], int *buff_ind);
int buffer_append(char buffer[], int *buff_ind, const char *str);

/**
 * print_unknown_format - Print the message for an unknown format.
 * @buffer: An array of characters.
 * @buff_ind: The index at which the next character should be added,
 *            representing the length.
 * Return: The number of characters printed for the unknown format.
 */
int print_unknown_format(char buffer[], int *buff_ind)
{
	int len = 0;

	len += buffer_append(buffer, buff_ind, "%r");

	return (len);
}

/**
 * _printf - Custom printf function.
 * @format: The format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, iPrinted = 0, iPrinted_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			iPrinted_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = g_flags(format, &i);
			width = g_width(format, &i, list);
			precision = g_precision(format, &i, list);
			size = g_size(format, &i);
			++i;
			if (format[i] == 'r')
			{
				iPrinted = print_unknown_format(buffer, &buff_ind);
			}
			else
			{
				iPrinted = print_with_format(format, &i, list, buffer,
					flags, width, precision, size);
			}
			if (iPrinted == -1)
				return (-1);
			iPrinted_chars += iPrinted;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (iPrinted_chars);
}

/**
 * print_buffer - Print the contents of the buffer if it exists.
 * @buffer: An array of characters.
 * @buff_ind: The index at which the next character should be added,
 * representing the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

/**
 * buffer_append - Appends a string to the buffer.
 * @buffer: An array of characters.
 * @buff_ind: The index at which the next character should be added,
 * representing the length.
 * @str: The string to append to the buffer.
 * Return: The number of characters appended.
 */
int buffer_append(char buffer[], int *buff_ind, const char *str)
{
	int len = 0;
	int i = 0;

	if (buffer == NULL || buff_ind == NULL || str == NULL)
		return (-1);

	while (str[i] != '\0')
	{
		buffer[*buff_ind] = str[i];
		(*buff_ind)++;
		len++;
		i++;
	}

	return (len);
}
