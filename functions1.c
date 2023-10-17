#include "main.h"

/**
* print_hexa - Print a hexadecimal number in lowercase or uppercase.
*
* This function converts a number into a hexadecimal representation using the specified character mapping (either lowercase or uppercase).
*
* @types: Argument list with the number to be printed.
* @map_to: Array of values to map the number to (e.g., "0123456789abcdef" or "0123456789ABCDEF").
* @buffer: Output buffer for printing the hexadecimal representation.
* @flags: Formatting flags for special handling (unused in this function).
* @flag_ch: Flag to determine whether to use lowercase ('x') or uppercase ('X') mapping.
* @width: Field width for formatting (unused in this function).
* @precision: Precision setting (unused in this function).
* @size: Size specifier (unused in this function).
*
* Return: The number of characters printed, representing the hexadecimal representation of the input number.
*/

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
* print_unsigned - Print an unsigned number.
*
* This function prints an unsigned number based on the provided arguments.
*
* @types: Argument list with the unsigned number to be printed.
* @buffer: Output buffer for the printed number.
* @flags: Formatting flags (unused in this function).
* @width: Field width for formatting (unused in this function).
* @precision: Precision setting (unused in this function).
* @size: Size specifier (unused in this function).
*
* Return: The number of characters printed, representing the unsigned number.
*/

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
* print_hexadecimal - Print an unsigned number in hexadecimal format.
*
* This function converts an unsigned number into a hexadecimal representation.
*
* @types: Argument list with the unsigned number to be printed.
* @buffer: Output buffer for the hexadecimal representation.
* @flags: Formatting flags (unused in this function).
* @width: Field width for formatting (unused in this function).
* @precision: Precision setting (unused in this function).
* @size: Size specifier (unused in this function).
*
* Return: The number of characters printed, representing the hexadecimal representation of the unsigned number.
*/

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
* print_string - Print a string.
*
* This function prints a string based on the provided arguments.
*
* @types: Argument list with the string to be printed.
* @buffer: Output buffer for the printed string.
* @flags: Formatting flags (unused in this function).
* @width: Field width for formatting.
* @precision: Precision specification (unused in this function).
* @size: Size specifier (unused in this function).
*
* Return: The number of characters printed, representing the string.
*/

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
* print_percent - Print a percent sign.
*
* This function prints a percent sign ('%') based on the provided arguments.
*
* @types: Argument list (unused in this function).
* @buffer: Output buffer for the printed percent sign.
* @flags: Formatting flags (unused in this function).
* @width: Field width for formatting.
* @precision: Precision specification (unused in this function).
* @size: Size specifier (unused in this function).
*
* Return: The number of characters printed, which is always 1 for a percent sign.
*/

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

