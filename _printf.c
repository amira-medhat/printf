#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* _write_char - Writes a character to stdout
* @c: The character to write
* @char_counter: Pointer to the character count
*/
void _write_char(char c, int *char_counter)
{
	write(1, &c, 1);
	(*char_counter)++;
}

/**
* _write_str - Writes a string to stdout
* @str: The string to write
* @char_counter: Pointer to the character count
*/
void _write_str(char *str, int *char_counter)
{
	int str_len = 0;

	while (str && str[str_len])
	str_len++;
	if (str == NULL)
		str = "(null)";
	write(1, str, str_len);
	(*char_counter) += str_len;
}

/**
* _write_int - Writes an integer to stdout
* @num: The integer to write
* @char_counter: Pointer to the character count
*/
void _write_int(int num, int *char_counter)
{
	int num_len = 0;
	int temp = num;
	char num_str[12];
	char *num_ptr;

	if (temp == 0)
		num_len = 1;
	else if (temp < 0)
	{
		num_len++;
		temp = -temp;
	}
	while (temp != 0)
	{
		temp /= 10;
		num_len++;
	}

	num_ptr = num_str + num_len - 1;

	if (num < 0)
	{
		num_str[0] = '-';
		num = -num;
	while (num > 0)
	{
		*num_ptr = num % 10 + '0';
		num /= 10;
		num_ptr--;
	}

	write(1, num_ptr, num_len);
	char_counter += num_len;
	}
	else
	{
	while (num > 0)
	{
		*num_ptr = num % 10 + '0';
		num /= 10;
		num_ptr--;
	}

	write(1, num_ptr + 1, num_len);
	char_counter += num_len;
	}
}

/**
* _write_ptr - Writes a pointer to stdout
* @ptr: The pointer to write
* @char_counter: Pointer to the character count
*/
void _write_ptr(void *ptr, int *char_counter)
{
	char ptr_str[20];
	unsigned long int ptr_val = (unsigned long int)ptr;
	int ptr_len = 0;
	char reversed_ptr_str[20];
	int i;

	if (ptr_val == 0)
	{
		ptr_str[0] = '0';
		ptr_len = 1;
	}
	else
	{
		while (ptr_val != 0)
		{
		int digit = ptr_val % 16;
		ptr_str[ptr_len] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
		ptr_val /= 16;
		ptr_len++;
		}
	}

	ptr_str[ptr_len++] = 'x';
	ptr_str[ptr_len++] = '0';

	
	for (i = 0; i < ptr_len; i++)
		reversed_ptr_str[i] = ptr_str[ptr_len - i - 1];

	write(1, reversed_ptr_str, ptr_len);
	(*char_counter) += ptr_len;
}


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
		_write_char(*format, &char_counter);
	}
	else
	{
		format++;
		if (*format == '\0')
			break;

		if (*format == 'c')
		{
			char c = va_arg(args_list, int);
			_write_char(c, &char_counter);
		}
		else if (*format == 's')
		{
			char *str = va_arg(args_list, char *);
			_write_str(str, &char_counter);
		}
		else if (*format == 'd' || *format == 'i')
		{
			int num = va_arg(args_list, int);
			_write_int(num, &char_counter);
		}
		else if (*format == 'p')
		{
			void *ptr = va_arg(args_list, void *);
			_write_ptr(ptr, &char_counter);
		}	
		else if (*format == '%')
		{
			_write_char('%', &char_counter);
		}
	}
	format++;
	}
	va_end(args_list);
	return (char_counter);
}
