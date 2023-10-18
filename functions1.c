#include "main.h"

/**
* p_unsigned - Print an unsigned number.
* @types: List of arguments.
* @buffer: Buffer array for printing.
* @flags: Active formatting flags.
* @width: Width specifier.
* @precision: Precision specification.
* @size: Size specifier.
*
* Return: Number of characters printed.
*/
int p_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int iNum = va_arg(types, unsigned long int);

	iNum = convert_size_unsgnd(iNum, size);

	if (iNum == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (iNum > 0)
	{
		buffer[i--] = (iNum % 10) + '0';
		iNum /= 10;
	}

	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}

/**
* p_octal - Print an unsigned number in octal notation.
* @types: List of arguments.
* @buffer: Buffer array for printing.
* @flags: Active formatting flags.
* @width: Width specifier.
* @precision: Precision specification.
* @size: Size specifier.
*
* Return: Number of characters printed.
*/
int p_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int iNum = va_arg(types, unsigned long int);
	unsigned long int init_num = iNum;

	UNUSED(width);

	iNum = convert_size_unsgnd(iNum, size);

	if (iNum == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (iNum > 0)
	{
		buffer[i--] = (iNum % 8) + '0';
		iNum /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}

/**
* p_hexadecimal - Print an unsigned number in hexadecimal notation.
* @types: List of arguments.
* @buffer: Buffer array for printing.
* @flags: Active formatting flags.
* @width: Width specifier.
* @precision: Precision specification.
* @size: Size specifier.
*
* Return: Number of characters printed.
*/
int p_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (p_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
* p_hexa_upper - Print an unsigned number in
* uppercase hexadecimal notation.
* @types: List of arguments.
* @buffer: Buffer array for printing.
* @flags: Active formatting flags.
* @width: Width specifier.
* @precision: Precision specification.
* @size: Size specifier.
*
* Return: Number of characters printed.
*/
int p_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (p_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
* p_hexa - Print a hexadecimal number in lowercase or uppercase.
* @types: List of arguments.
* @map_to: Array of values to map the number to.
* @buffer: Buffer array for printing.
* @flags: Active formatting flags.
* @flag_ch: Active formatting flags.
* @width: Width specifier.
* @precision: Precision specification.
* @size: Size specifier.
*
* Return: Number of characters printed.
*/
int p_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int iNum = va_arg(types, unsigned long int);
	unsigned long int init_num = iNum;

	UNUSED(width);

	iNum = convert_size_unsgnd(iNum, size);

	if (iNum == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (iNum > 0)
	{
		buffer[i--] = map_to[iNum % 16];
		iNum /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}