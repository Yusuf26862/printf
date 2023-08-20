#include <stdarg.h>
#include "main.h"

/**
 * _printf - print formated string.
 * @format: the string to be formatted.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, *format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				putchar('%');
			else if (*format == 'c')
				int ch = va_arg(args, int);

				putchar(ch);
			else if (*format == 's')
				char *str = va_arg(args, char *);

				while (*str)
					putchar(*str);
					str++;
		}
		else if (*format == '\\')
		{
			format++;
			if (*format == 'n')
				putchar('\n');
		}
		else
			putchar(*format);
		format++;
	}
	return (0);
}
