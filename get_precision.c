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
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
