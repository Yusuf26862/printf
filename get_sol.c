#include "main.h"

/**
 * get_sol - turns on sol if _printf finds
 * a sol modifier in the format string
 * @s: character that holds the sol specifier
 * @f: pointer to the struct sol in which we turn the sol on
 *
 * Return: 1 if a sol has been turned on, 0 otherwise
 */
int get_sol(char s, sol_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->pl = 1;
			i = 1;
			break;
		case ' ':
			f->sp = 1;
			i = 1;
			break;
		case '#':
			f->ha = 1;
			i = 1;
			break;
	}

	return (i);
}
