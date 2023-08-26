#include "main.h"
#include <stdarg.h>
#include <unistd.h> // Include this for write

/**
* _printf - Custom printf function
* @format: Format string
*
* Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
	int char_counter = 0;
	va_list args_list;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	if ((format[0] == '%' && format[1] == ' ') && format[2] == '\0')
		return (-1);

	va_start(args_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_counter++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				char c = va_arg(args_list, int);
				write(1, &c, 1);
				char_counter++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args_list, char *);
				int str_len = 0;
				while (str && str[str_len])
					str_len++;
				if (str == NULL)
					str = "(null)";
				write(1, str, str_len);
				char_counter += str_len;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args_list, int);
				int num_len = 0;
				while (num)
				{
					num = num / 10;
					num_len++;
				}
				char_counter += num_len;
				write(1, &num, num_len);
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				char_counter++;
			}
		}
	format++;
	}
	va_end(args_list);
	return (char_counter);
}
