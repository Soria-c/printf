#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int str_len(char *str);
int f_sel(const char *format, char *fs, char *s, int sz, va_list args, int z, int w);
int p_c(const char *format, char *f, int sz, va_list args, int op, int z, int w);
int p_d(const char *format, char *f, int sz, va_list args, int op, int z, int w);
int p_p(const char *format, char *f, int sz, va_list args, int op, int z, int w);
int p_s(const char *format, char *f, int sz, va_list args, int op, int z, int w);
int print_v(const char *format, char *f, int sz, va_list args, int op, int z, int w);
void str_rev(char *s);
void to_string(char *s, int n);
int check(char *fs, char *s, int *op, int sz);
int fs_init(char *s, va_list args);

#endif /*MAIN_H*/
