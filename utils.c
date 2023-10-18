
#include "main.h"

/**
 * i_printable - Determine if a character is printable.
 * @c: The character to evaluate.
 *
 * Return: 1 if 'c' is printable, 0 otherwise.
 */
int i_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * hexa_code - Appends ASCII in hexadecimal
 * representation to a buffer.
 * @buffer: Array of characters.
 * @i: Index at which to start appending.
 * @ascii_code: ASCII code.
 * Return: Always 3 (the number of characters appended).
 */
int hexa_code(char ascii_code, char buffer[], int i)
{
	char to_map[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = to_map[ascii_code / 16];
	buffer[i] = to_map[ascii_code % 16];

	return (3);
}

/**
 * i_digit - Determine if a character is a digit.
 * @c: The character to evaluate.
 *
 * Return: 1 if 'c' is a digit, 0 otherwise.
 */
int i_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Convert a number to the specified data type.
 * @num: The number to be converted.
 * @size: An integer indicating the data type for the conversion.
 *
 * Return: The value of 'num' after conversion.
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Convert a number to the specified data type.
 * @num: The number to be converted.
 * @size: An integer indicating the target data type for the conversion.
 *
 * Return: The value of 'num' after conversion.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}