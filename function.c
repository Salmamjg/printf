#include "main.h"

/**
* print_char - Print a single character.
*
* This function prints a single character based on the provided arguments.
*
* @types: Argument list with the character to be printed.
* @buffer: Output buffer where the character is printed.
* @flags: Formatting flags for special handling.
* @width: Field width for formatting.
* @precision: Precision setting for character output.
* @size: Size specifier for character printing.
*
* Return: The number of characters printed (always 1 for a single character).
*/

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    char c = va_arg(types, int);
    return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
* print_int - Print an integer value.
*
* This function prints an integer based on the provided arguments.
*
* @types: Argument list with the integer to be printed.
* @buffer: Output buffer where the integer is printed.
* @flags: Formatting flags for special handling.
* @width: Field width for formatting.
* @precision: Precision setting for integer output.
* @size: Size specifier for integer printing.
*
* Return: The number of characters printed, which may vary depending on the integer value.
*/

int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    int is_negative = 0;
    long int n = va_arg(types, long int);
    unsigned long int num;

    n = convert_size_number(n, size);

    if (n == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';
    num = (unsigned long int)n;

    if (n < 0)
    {
        num = (unsigned long int)((-1) * n);
        is_negative = 1;
    }

    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
* print_binary - Print a non-negative integer in binary format.
*
* This function takes a non-negative integer as input and prints it in binary format.
* It's used to convert a number into a sequence of 0s and 1s.
*
* @types: Argument list with the non-negative integer to be printed.
* @buffer: Output buffer where the binary representation is printed.
* @flags: Formatting flags for special handling (unused in this function).
* @width: Field width for formatting (unused in this function).
* @precision: Precision setting (unused in this function).
* @size: Size specifier (unused in this function).
*
* Return: The number of characters printed, representing the binary representation of the input integer.
*/

int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    unsigned int n, m, i, sum;
    unsigned int a[32];
    int count;

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    n = va_arg(types, unsigned int);
    m = 2147483648; /* (2 ^ 31) */
    a[0] = n / m;

    for (i = 1; i < 32; i++)
    {
        m /= 2;
        a[i] = (n / m) % 2;
    }

    for (i = 0, sum = 0, count = 0; i < 32; i++)
    {
        sum += a[i];
        if (sum || i == 31)
        {
            char z = '0' + a[i];
            write(1, &z, 1);
            count++;
        }
    }

    return (count);
}

/**
* print_octal - Print a non-negative integer in octal notation.
*
* This function takes a non-negative integer as input and prints it in octal (base-8) format.
* It's used to convert a number into a sequence of digits (0-7) representing the octal representation.
*
* @types: Argument list with the non-negative integer to be printed.
* @buffer: Output buffer where the octal representation is printed.
* @flags: Formatting flags for special handling (unused in this function).
* @width: Field width for formatting (unused in this function).
* @precision: Precision setting (unused in this function).
* @size: Size specifier (unused in this function).
*
* Return: The number of characters printed, representing the octal representation of the input integer.
*/

int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
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
        buffer[i--] = (num % 8) + '0';
        num /= 8;
    }

    if (flags & F_HASH && init_num != 0)
        buffer[i--] = '0';

    i++;

    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
* print_hexa_upper - Print a non-negative integer in uppercase hexadecimal format.
*
* This function takes a non-negative integer as input and prints it in hexadecimal (base-16) format using uppercase letters (A-F).
* It's used to convert a number into a sequence of characters representing the hexadecimal representation with capital letters.
*
* @types: Argument list with the non-negative integer to be printed.
* @buffer: Output buffer where the hexadecimal representation is printed.
* @flags: Formatting flags for special handling (unused in this function).
* @width: Field width for formatting (unused in this function).
* @precision: Precision setting (unused in this function).
* @size: Size specifier (unused in this function).
*
* Return: The number of characters printed, representing the uppercase hexadecimal representation of the input integer.
*/

int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size));
}
