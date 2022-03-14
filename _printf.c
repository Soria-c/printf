#include "main.h"

/**
 * _printf - prints a formatted string
 * @format: imput string
 *
 * Return: number of bytes if is SUCCESS, -1 otherwise.
 */

int _printf(const char *format, ...)
{
	va_list args;
	char *f_check, init[1024];
	int i, lenght, bytes, s, k;

	f_check = (char *)format;
	lenght = str_len(f_check);
	va_start(args, format);
	for (i = 0; *f_check != '%' && *f_check != 0; i++, f_check++)
		continue;
	if (i == lenght)
	{
		write(1, format, lenght);
		return (lenght);
	}
	else
	{
		for (k = 0; k < 1024; k++)
			init[k] = 'r';
		init[k] = '\0';
		s = f_sel(format, init, f_check, i, args, 0);
	}
	if (s != 0)
	{
		write(2, "Unsupported format\n", 20);
		return (-1);
	}
	bytes = str_len(init);
	write(1, init, bytes);
	return (bytes);
}
