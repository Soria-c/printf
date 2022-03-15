#include "main.h"

/**
 * print_p - copies args in f
 * @format: input string
 * @f: buffer
 * @sz: number of bytes before %
 * @args: arguments list
 * @op: operation number
 * @z: offset
 *
 * Return: -1 is special in f_sel is triggered, 0 otherwise.
 */

int print_p(const char *format, char *f, int sz, va_list args, int op, int z, int w)
{
	int copy, i, j, r;
	char *f_check;

	r = 0;
	for (copy = 0; copy < sz; copy++)
		f[copy] = format[z + copy];
	f[copy] = '%';
	j = copy + 1;
	for (; format[copy + z + op + 1] != '\0'; copy++)
		f[copy + 1] = format[copy + z + op + 1];
	f[copy + 1] = '\0';
	f = f + j;
	f_check = f;
	for (i = 0; *f_check != '%' && *f_check != 0; i++, f_check++)
		continue;
	z = z + sz + op + 1;
	r = f_sel(format, f, f_check, i, args, z, w);
	if (r == -1)
		return (r);
	return (r);
}
