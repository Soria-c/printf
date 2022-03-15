#include "main.h"

/**
 * f_sel - selects format case
 * @format: input string
 * @fs: buffer
 * @s: address of first incidence of % in fs
 * @sz: number of bytes before %
 * @args: arguments list
 * @z: offset
 *
 * Return: 0 if f_sel is SUCCESS and 1 otherwise.
 */

int f_sel(const char *format, char *fs, char *s, int sz, va_list args, int z)
{
	int op, i, of = 2;
	char *ff;

	ff = (char *)format;
	if (*s == '\0')
		return (0);
	for (op = 0; s[op] < 'a'; op++)
		continue;
	if (s[1] == '%')
		op = 1;
	switch (s[op])
	{
		case 'c':
			print_c(format, fs, sz, args, op, z);
			break;
		case 'd':
			print_d(format, fs, sz, args, op, z);
			break;
		case 'i':
			print_d(format, fs, sz, args, op, z);
			break;
		case '%':
			print_p(format, fs, sz, args, op, z);
			break;
		case 's':
			print_s(format, fs, sz, args, op, z);
			break;
		default:
			if (format[0] == '%')
				of = 1;
			if (str_len(ff) == 2)
				return (2);
			fs = fs + op + of;
			z = z + op + of;
			s = fs;
			for (i = 0; *s != '%' && *s != '\0'; i++, s++)
				continue;
			f_sel(format, fs, s, i, args, z);
	}
	return (0);
}
