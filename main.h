#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1

/**
* struct fmt - Format specification structure.
*
* @fmt: The format specifier.
* @fn: The associated function pointer.
*/
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
* typedef struct fmt fmt_t - Format specification type.
*
* @fmt: The format specifier.
* @fn: The associated function pointer.
*/
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int print_with_format(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);


/* Function for Printing a String in ROT13 Encryption */
/* Function for Reversing and Printing a String */
/* Functions for Handling Other Specifiers */
/* Function for Printing Memory Addresses */
/* Function for Printing Non-Printable Characters */
/* Functions for Number Printing */
/* Functions for Character and String Printing */
/* Width Handling Functions */

int p_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int p_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int p_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

int p_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int p_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int g_flags(const char *format, int *i);
int g_width(const char *format, int *i, va_list list);
int g_precision(const char *format, int *i, va_list list);
int g_size(const char *format, int *i);

int p_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int p_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_numbers(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointers(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsignd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

int i_printable(char);
int hexa_code(char, char[], int);
int i_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif 
/* END OF MAIN_H */