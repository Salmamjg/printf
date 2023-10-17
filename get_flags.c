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
int get_flag(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}

	return (i);
}