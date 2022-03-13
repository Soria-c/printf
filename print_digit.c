#include "main.h"

void print_digit(const char *format, char *f_s, int sz, va_list args, int num_opt, int z)
{
	int copy, i, j;
	char *f_check;

	for (copy = 0; copy < sz; copy++)
		f_s[copy] = format[z + copy];
	f_s[copy] = va_arg(args, int) + '0';
	j = copy + 1;
	for (; copy + 1 < str_len(f_s); copy++)
		f_s[copy + 1] = format[copy + z + num_opt + 1];
	f_s[copy + 1] = '\0';
	f_check = f_s;
	f_s = f_s + j;
	for (i = 0; *f_check != '%' && *f_check != 0; i++, f_check++)
		;
	z = z + sz + num_opt + 1;
	f_select(format, f_s, f_check, i - j, args, z);
}
