 #include "main.h"

/**
* g_flags - Extracts active flags from a formatted string.
* @format: The formatted string containing the flags.
* @i: The current position in the string.
* Return: The extracted flags.*/
int g_flags(const char *format, int *i)
{
	int j, iCurr;
	int iFlags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (iCurr = *i + 1; format[iCurr] != '\0'; iCurr++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[iCurr] == FLAGS_CH[j])
			{
				iFlags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = iCurr - 1;

	return (iFlags);
}