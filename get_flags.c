#include "main.h"

/**
 * get_flag - Set flags in the flags_t struct based on a flag character.
 *
 * This function takes a character `s` that represents a flag specifier and
* sets the corresponding flag in the provided flags_t struct `f` to 1.
*
* @s: Character holding the flag specifier.
* @f: Pointer to the flags_t struct where flags are turned on.
*
* Return: 1 if a flag has been successfully turned on, 0 otherwise.
*
*/
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
