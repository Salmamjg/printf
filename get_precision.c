#include "main.h"

/**
* g_precision - Determine the precision for formatting a string.
* @format: The format string for the argument list.
* @i: The index of the current argument.
* @list: A list of arguments.
*
* Return: The calculated precision value.
*/
int g_precision(const char *format, int *i, va_list list)
{
	int iCurr = *i + 1;
	int iPrecision = -1;

	if (format[iCurr] != '.')
		return (iPrecision);

	iPrecision = 0;

	for (iCurr += 1; format[iCurr] != '\0'; iCurr++)
	{
		if (i_digit(format[iCurr]))
		{
			iPrecision *= 10;
			iPrecision += format[iCurr] - '0';
		}
		else if (format[iCurr] == '*')
		{
			iCurr++;
			iPrecision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = iCurr - 1;

	return (iPrecision);
}