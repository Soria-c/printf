#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
 	char *f_check, *init;
	int i, lenght, k;

	f_check = (char *)format;
	lenght = str_len(f_check);
	va_start(args, format);
	for (i = 0; *f_check != '%' && *f_check != 0; i++, f_check++)
		;
	if (i == lenght)
		write(1, format, lenght);
	else
	{
		init = malloc(lenght + 1);
		for (k = 0; k < lenght; k++)
			init[k] = 'a';
		init[k] = 0; 
		f_select(format, init, f_check, i, args, 0);
	}
	write(1, init, str_len(init));
	free(init);
	return (0);
}
