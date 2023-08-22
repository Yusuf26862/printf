#include "main.h"

/**
 * print_char - Prints a single character.
 * @list: list of arguments.
 * Return: Will return the amount of characters printed.
 */

int print_char(va_list list)
{
	_write_char(va_arg(list, int));
	return (1);
}

/**
 * print_string - Prints string of characters.
 * @list: list of arguments.
 * Return: Will return the amount of characters printed.
 */

int print_string(va_list list)
{
	int index;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	for (index = 0; str[index] != '\0'; index++)
	{
		_write_char(str[index]);
	}
	return (index);
}

/**
 * print_percent - Prints a percent symbol
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */

int print_percent(__attribute__((unused))va_list list)
{
	_write_char('%');
	return (1);
}

/**
 * print_integer - Prints an integer
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_integer(va_list list)
{
	int num_length;

	num_length = print_number(list);
	return (num_length);
}
