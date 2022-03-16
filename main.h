#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int str_len(char *str);
int fs(const char *format, char *fs, char *s, int sz, va_list a, int z, int w);
int pc(const char *format, char *f, int sz, va_list arg, int op, int z, int w);
int pd(const char *format, char *f, int sz, va_list arg, int op, int z, int w);
int pp(const char *format, char *f, int sz, va_list arg, int op, int z, int w);
int ps(const char *format, char *f, int sz, va_list arg, int op, int z, int w);
int pv(const char *format, char *f, int sz, va_list arg, int op, int z, int w);
void str_rev(char *s);
void to_string(char *s, int n);
int check(char *fs, char *s, int *op, int sz);
int fs_init(char *s, va_list args);

#endif /*MAIN_H*/
