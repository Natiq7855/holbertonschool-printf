#include "main.h"
#include <stdarg>

/**
 * _printf - produces output according to a format
 * @format: character string containing directives
 * Return: the number of characters printed
 */


int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char *str;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			/* Handle %c - Character */
			if (format[i] == 'c')
				count += _putchar(va_arg(args, int));
			/* Handle %s - String */
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					count += _putchar(*str);
					str++;
				}
			}
			/* Handle %% - Percent */
			else if (format[i] == '%')
				count += _putchar('%');
			/* Handle unknown specifiers */
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}