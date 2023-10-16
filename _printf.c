#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 * @...: other arguments
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	choose c[] = {
		{"%c", prt_char}, {"%s", prt_str}, {"%%", prt_pers}, {"%i", prt_int}
	};

	va_list param;
	int len = 0;
	int i = 0;
	int j = 0;

	va_start(param, format);

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Etqt:
	while (format[i] != '\0')
	{
		j = 0;
		while (j < 4)
		{
			if (c[j].cle[0] == format[i] && c[j].cle[1] == format[i + 1])
			{
				len = len + c[j].f(param);
				i = i + 2;
				goto Etqt;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}


	va_end(param);
	return (len);
}
