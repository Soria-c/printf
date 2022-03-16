#include "main.h"

/**
 * pc - copies args in f
 * @format: input string
 * @f: buffer
 * @sz: number of bytes before %
 * @arg: arguments list
 * @op: operation number
 * @z: offset
 * @w: flag
 *
 * Return: -1 is special in f_sel is triggered, 0 otherwise.
 */

int pc(const char *format, char *f, int sz, va_list arg, int op, int z, int w)
{
	int copy, i, j, r, fl;
	char *f_check;
	va_list args2;

	j = r = fl = 0;
	va_copy(args2, arg);
	for (copy = 0; copy < sz; copy++)
		f[copy] = format[z + copy];
	if (va_arg(args2, int))
		f[copy] = va_arg(arg, int);
	else
	{
		fl = 3;
		va_arg(arg, int);
		f--;
	}
	va_end(args2);
	j = copy + 1;
	for (; format[copy + z + op + 1] != '\0'; copy++)
		f[copy + 1] = format[copy + z + op + 1];
	f[copy + 1] = '\0';
	f = f + j;
	f_check = f;
	for (i = 0; *f_check != '%' && *f_check != 0; i++, f_check++)
		continue;
	z = z + sz + op + 1;
	r = fs(format, f, f_check, i, arg, z, w);
	if (fl == 3)
		return (3);
	if (r == -1)
		return (r);
	return (r);
}

/**
 * pv - copies args in f
 * @format: input string
 * @f: buffer
 * @sz: number of bytes before %
 * @arg: arguments list
 * @op: operation number
 * @z: offset
 * @w: flag
 *
 * Return: -1 is special in f_sel is triggered, 0 otherwise.
 */

int pv(const char *format, char *f, int sz, va_list arg, int op, int z, int w)
{
	int copy, i, j, r;
	char *f_check;

	j = r = 0;
	for (copy = 0; copy < sz; copy++)
		f[copy] = format[z + copy];
	f[copy] = format[z + copy];
	j = copy;
	if (format[z + copy + 1] == ' ')
		r = 1;
	for (; format[copy + z + op - r] != '\0'; copy++)
		f[copy + 1] = format[copy + z + op - r];
	f[copy + 1] = '\0';
	f = f + j + 2 + r;
	f_check = f;
	for (i = 0; *f_check != '%' && *f_check != 0; i++, f_check++)
		continue;
	z = z + sz + op + 1;
	w = 1;
	fs(format, f, f_check, i, arg, z, w);
	return (0);
}
