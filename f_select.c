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
	int op, r;

	r = 0;
	for (op = 0; s[op] < 'a'; op++)
		continue;
	if (s[1] == '%')
		op = 1;
	switch (s[op])
	{
		case 'c':
			r = print_c(format, fs, sz, args, op, z);
			break;
		case 'd':
			r = print_d(format, fs, sz, args, op, z);
			break;
		case 'i':
			r = print_d(format, fs, sz, args, op, z);
			break;
		case '%':
			r = print_p(format, fs, sz, args, op, z);
			break;
		case 's':
			r = print_s(format, fs, sz, args, op, z);
			break;
		default:
			if (*s == '\0')
				return (0);
			return (1);
	}
	if (r == 1)
	{
		return (1);
	}
	return (0);
}
