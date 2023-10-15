#include "main.h"

/**
 * _printf - Custom printf implementation with variable arguments.
 * @format: A format string that specifies how to format the output.
 * @...: Variable number of arguments based on the format string.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	int printed_chars;

	fmt_list func_list[] =	{
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}
	};

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	printed_chars = handle_specifiers(format, func_list, args);
	va_end(args);

	return (printed_chars);
}
