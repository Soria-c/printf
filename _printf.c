#include "main.h"
int fs_init(char *s, va_list args)
{
	int i, j;
	char *s2;
	va_list args3;
	
	va_copy(args3, args);
	s2 = s;
	j = 0;
	for (i = 0; s2[i] != '\0'; i++)
	{
		if (s2[i] == '%')
		{
			if (s2[i + 1] == 'c')
			{
				if (va_arg(args3, int) == '\0')
					j++;
			}
			else if (s2[i + 1] == 'd' || s2[i + 1] == 'i')
				va_arg(args3, int);
			else if (s2[i + 1] == 's')
				va_arg(args3, char *);
		}
	}
	va_end(args3);
	return (j);
}
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
	int i, lenght, bytes, s, k, total;

	if (!format)
		return (-1);
	f_check = (char *)format;
	lenght = str_len(f_check);
	va_start(args, format);
	total = fs_init(f_check, args);
	for (i = 0; *f_check != '%' && *f_check != 0; i++, f_check++)
		continue;
	if (i == lenght)
	{
		write(1, format, lenght);
		va_end(args);
		return (lenght);
	}
	else
	{
		for (k = 0; k < lenght; k++)
			init[k] = format[k];
		init[k] = '\0';
		s = f_sel(format, init, f_check, i, args, 0, 0);
		va_end(args);
	}
	bytes = str_len(init);
	write(1, init, bytes);
	if (s == 3)
		return (bytes + total);
	if (s == -1)
		return (-1);
	return (bytes);
}
