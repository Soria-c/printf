#include "main.h"

/**
 * pd - copies args in f
 * @format: input string
 * @f: buffer
 * @sz: number of bytes before %
 * @arg: arguments list
 * @op: operation number
 * @z: offset
 * @w: flag
 *
 * Return: -1 is special case in f_sel is triggered, 0 otherwise.
 */

int pd(const char *format, char *f, int sz, va_list arg, int op, int z, int w)
{
	int copy, i, j, k, r;
	char *f_check, string[20];

	r = 0;
	for (copy = 0; copy < sz; copy++)
		f[copy] = format[z + copy];
	to_string(string, va_arg(arg, int));
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
	r = fs(format, f, f_check, i, arg, z, w);
	if (r == -1)
		return (r);
	return (r);
}
