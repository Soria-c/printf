#include "main.h"

int f_select(const char *format, char *fs, char *s, int sz, va_list args, int z)
{
	int num_opt;
	
	if (str_len(s) == 0)
		return (0);
	for (num_opt = 0; s[num_opt] < 'a'; num_opt++)
		;
	switch(s[num_opt])
	{
		case 'c':
			print_char(format, fs, sz, args, num_opt, z);
			break;
		case 'd':
			print_digit(format, fs, sz, args, num_opt, z);
			break;
	}
	return (0);
}
