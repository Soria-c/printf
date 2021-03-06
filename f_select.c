#include "main.h"

/**
 * fs - selects format case
 * @format: input string
 * @fs: buffer
 * @s: address of first incidence of % in fs
 * @sz: number of bytes before %
 * @a: arguments list
 * @z: offset
 * @w: flag
 *
 * Return: 0 if f_sel is SUCCESS and 1 otherwise.
 */

int fs(const char *format, char *fs, char *s, int sz, va_list a, int z, int w)
{
	int op, r;

	if (*s == '\0')
		return (0);
	for (op = 0; s[op + 1] < '!' && s[op + 1] != '\0'; op++)
		;
	if (w == 1)
		w = 2;
	if (!s[op + 1] || ((s[op + 1] > 47 && s[op + 1] < 58) && !s[op + 2]))
	{
		if (w == 2)
			return (0);
		r = check(fs, s, &op, sz);
		if (r == -1)
			return (-1);
	}
	op++;
	switch (s[op])
	{
		case 'c':
			r = pc(format, fs, sz, a, op, z, w);
			break;
		case 'd':
		case 'i':
			r = pd(format, fs, sz, a, op, z, w);
			break;
		case '%':
			r = pp(format, fs, sz, a, op, z, w);
			break;
		case 's':
			r = ps(format, fs, sz, a, op, z, w);
			break;
		default:
			r = pv(format, fs, sz, a, op, z, w);
	}
	if (r == -1)
		return (-1);
	return (r);
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
