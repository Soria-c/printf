#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int str_len(char *str);
int f_select(const char *format, char *fs, char *s, int sz, va_list args, int z);
void print_char(const char *format, char *f_s, int sz, va_list args, int num_opt, int z);
char *fs_init(char *s, int n);

#endif /*MAIN_H*/

