#include "main.h"

/**
* get_precision - Calculate printing precision from format string.
* @format: The formatted string.
* @i: A pointer to the current position in the format string.
* @list: The list of arguments.
*
* Description:
* This function calculates the precision for printing based on the format string,
* the current position in the format string, and the argument list.
*
* Return:
* The calculated precision value. If no precision is specified, -1 is returned.
*/
int get_precision(const char *format, int *i, va_list list)
{
	int curr = *i + 1;
	int prec= -1;

	if (format[curr] != '.')
		return (prec);

	prec = 0;

	for (curr += 1; format[curr] != '\0'; curr++)
	{
		if (is_digit(format[curr]))
		{
			prec *= 10;
			prec += format[curr] - '0';
		}
		else if (format[curr] == '*')
		{
			curr++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr - 1;

	return (prec);
}