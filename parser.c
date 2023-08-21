#include "main.h"

/**
 * parser - Receives the main string and all the necessary parameters to
 * 	print a formated string.
 * @format: A string containing all the desired characters.
 * @f_list: A list of all the posible functions.
 * @arg_list: A list containing all the argumentents passed to the program.
 * Return: A total count of the characters printed.
 */

int parset(const char *format, conver_t f_list[], va_list arg_list)
{
	int i, j, p_value, printed_cha;
	
	printed_cha = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; f_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == f_list[j].sym[0])
				{
					p_value = f_list[j].f(arg_list);
					if (p_value == -1)
					{
						return (-1);
					}
					printed_cha += p_value;
					break;
				}
			}
			if (f_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_write_char(format[i]);
					_write_char(format[i + 1]);
					printed_cha = printed_cha + 2;
				}
				else
				{
					return (-1);
				}
			}
			i = i + 1;
		}
		else
		{
			_write_char(format[i]);
			printed_cha++;
		}
	}
	return (printed_cha);
}
