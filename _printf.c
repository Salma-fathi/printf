#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
int _strlen(char *str);

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed excluding the null byte 
 */

int _printf(const char *format, ...)
{
	va_list args;
	/*char *str,*/
      	char ch, *st;
	int len;

	va_start(args, format);
	/*str = va_arg(args, char *);*/
	len = 0;
        while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					ch = va_arg(args, int);
					write (1, &ch, 1);
					len++;
					printf("length check c:%d\n", len);
				       	break;
				case 's':
					st = va_arg(args, char *);
					write (1, st, _strlen(st));
					len = len + _strlen(st);
					printf("length check s:%d\n", len);
					break;
				default:
					break;
			}
		}
		else
		{
			write (1, format, 1);
			len++;
			printf("length check else:%d\n", len);
		}		
		format++;
	}
	va_end(args);
	return (len);
}

/**
 * _strlen - finds string length
 * @str: pointer to string
 *
 * Return: string length.
 */

int _strlen(char *str)
{
	int length = 0;
	while (*str != '\0')
	{
		str++;
		length++;
	}
	return (length);
}
