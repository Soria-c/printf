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

	if (*s == '\0')
		return (0);
	for (op = 0; s[op + 1] < '!' && s[op + 1] != '\0'; op++)
		;
	if (!s[op + 1] || ((s[op + 1] > 47 && s[op + 1] < 58) && !s[op + 2]))
	{
		r = check(fs, s, &op, sz);
		if (r == -1)
			return (-1);
	}
	op++;
	switch (s[op])
	{
		case 'c':
			r = print_c(format, fs, sz, args, op, z);
			break;
		case 'd':
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
			print_v(format, fs, sz, args, op, z);
	}
	if (r == -1)
		return (-1);
	return (0);
}
/**
 * check - checks special case of %
 * @fs: buffer
 * @s: address of first incidence of % in fs
 * @op: pointer to op
 * @sz: number of bytes before %
 * Return: -1 if special case exists, 0 if not
 */
int check(char *fs, char *s, int *op, int sz)
{
	for (*op = 0; s[*op + 1] < '!' && s[*op + 1] != '\0'; *op = *op + 1)
		;
	if (s[*op + 1] == '\0')
	{
		fs[sz] = '\0';
		return (-1);
	}
	if ((s[*op + 1] > 47 && s[*op + 1] < 58) && (!s[*op + 2]))
	{
		fs[sz] = '\0';
		return (-1);
	}
	return (0);
}

