#include "main.h"
#include <stdint.h>

/**
* p_pointer - Print the value of a pointer variable.
* @types: List of arguments.
* @buffer: Buffer array for printing.
* @flags: Active formatting flags.
* @width: Width specifier.
* @precision: Precision specification.
* @size: Size specifier.
*
* Return: Number of characters printed.
*/
int p_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
    char iExtra = 0, padd = ' ';
    int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; 
    uintptr_t num_addrs; 
    char map_to[] = "0123456789abcdef";
    void *addrs = va_arg(types, void *);

    UNUSED(width);
    UNUSED(size);

    if (addrs == NULL)
        return (write(1, "(nil)", 5));

    buffer[BUFF_SIZE - 1] = '\0';
    UNUSED(precision);

    num_addrs = (uintptr_t)addrs; 
    while (num_addrs > 0)
    {
        buffer[ind--] = map_to[num_addrs % 16];
        num_addrs /= 16;
        length++;
    }

    if ((flags & F_ZERO) && !(flags & F_MINUS))
        padd = '0';
    if (flags & F_PLUS)
        iExtra = '+', length++;
    else if (flags & F_SPACE)
        iExtra = ' ', length++;

    ind++;

    return (write_pointers(buffer, ind, length,
        width, flags, padd, iExtra, padd_start));
}

/**
* p_non_printable - Print ASCII codes in hexadecimal of
* non-printable characters.
* @types: List of arguments.
* @buffer: Buffer array for printing.
* @flags: Active formatting flags.
* @width: Width specifier.
* @precision: Precision specification.
* @size: Size specifier.
*
* Return: Number of characters printed.
*/
int p_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, iOffset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (i_printable(str[i]))
			buffer[i + iOffset] = str[i];
		else
			iOffset += hexa_code(str[i], buffer, i + iOffset);

		i++;
	}

	buffer[i + iOffset] = '\0';

	return (write(1, buffer, i + iOffset));
}

/**
* p_reverse - Print a reversed string.
* @types: List of arguments.
* @buffer: Buffer array for printing.
* @flags: Active formatting flags.
* @width: Width specifier.
* @precision: Precision specification.
* @size: Size specifier.
*
* Return: Number of characters printed.
*/
int p_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, iCount = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		iCount++;
	}
	return (iCount);
}

/**
* p_rot13string - Print a string in ROT13 encoding.
* @types: List of arguments.
* @buffer: Buffer array for printing.
* @flags: Active formatting flags.
* @width: Width specifier.
* @precision: Precision specification.
* @size: Size specifier.
*
* Return: Number of characters printed.
*/
int p_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int iCount = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				iCount++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			iCount++;
		}
	}
	return (iCount);
}