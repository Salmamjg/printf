#include "main.h"

/**
 * g_width - Determine the required
 * width for formatting and printing.
 * @format: The format string for printing the arguments.
 * @i: Index of the argument in the list.
 * @list: List of arguments to be printed.
 *
 * Return: The calculated printing width.
 */
int g_width(const char *format, int *i, va_list list)
{
	int iCurr;
	int iWidth = 0;

	for (iCurr = *i + 1; format[iCurr] != '\0'; iCurr++)
	{
		if (i_digit(format[iCurr]))
		{
			iWidth *= 10;
			iWidth += format[iCurr] - '0';
		}
		else if (format[iCurr] == '*')
		{
			iCurr++;
			iWidth = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = iCurr - 1;

	return (iWidth);
}