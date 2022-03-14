#include "main.h"

/**
 * print_s - copies args in f
 * @format: input string
 * @f: buffer
 * @sz: number of bytes before %
 * @args: arguments list
 * @op: operation number
 * @z: offset
 *
 * Return: 0 if f_sel is SUCCESS and 1 otherwise.
 */

int print_s(const char *format, char *f, int sz, va_list args, int op, int z)
{
	int copy, i, j, k, r;
	char *f_check, *string;

	r = 0;
	for (copy = 0; copy < sz; copy++)
		f[copy] = format[z + copy];
	string = va_arg(args, char *);
	for (k = 0; string[k] != '\0'; k++)
		f[copy + k] = string[k];
	j = copy + k;
	for (; format[copy + z + op + 1] != '\0'; copy++)
		f[copy + k] = format[copy + z + op + 1];
	f[copy + k] = '\0';
	f = f + j;
	f_check = f;
	for (i = 0; *f_check != '%' && *f_check != 0; i++, f_check++)
		continue;
	z = z + sz + op + 1;
	r = f_sel(format, f, f_check, i, args, z);
	if (r == 1)
		return (r);
	return (r);
}
