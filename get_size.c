#include "main.h"

/**
 * g_size - Determine the required size
 * for casting the argument.
 * @format: The format string for printing the arguments.
 * @i: Index of the argument in the list.
 *
 * Return: The calculated size for casting the argument.
 */
int g_size(const char *format, int *i)
{
	int iCurr = *i + 1;
	int iSize = 0;

	if (format[iCurr] == 'l')
		iSize = S_LONG;
	else if (format[iCurr] == 'h')
		iSize = S_SHORT;

	if (iSize == 0)
		*i = iCurr - 1;
	else
		*i = iCurr;

	return (iSize);
}