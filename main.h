#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int str_len(char *str);
int f_sel(const char *format, char *fs, char *s, int sz, va_list args, int z);
int print_c(const char *format, char *f, int sz, va_list args, int op, int z);
int print_d(const char *format, char *f, int sz, va_list args, int op, int z);
int print_p(const char *format, char *f, int sz, va_list args, int op, int z);
int print_s(const char *format, char *f, int sz, va_list args, int op, int z);
int print_v(const char *format, char *f, int sz, va_list args, int op, int z);
void str_rev(char *s);
void to_string(char *s, int n);
int check(char *fs, char *s, int *op, int sz);

#endif /*MAIN_H*/
