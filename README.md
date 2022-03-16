# Project _printf.

## Description
This Repositorie has all the code necessary for called our own version of function ``printf()``, which we (Carlos Soria and Yohel Cruz) rename ``_printf``.

The format string is composed of zero or more directives: ordinary characters (not %),\
which are copied unchanged to the output stream; and conversion specifications, each\
of which results in fetching zero or more subsequent arguments.  Each conversion\
specification is introduced by the character %, and ends with a conversion specifier.

The overall syntax of a conversion specification is:

%[$][flags][.precision][length modifier]conversion


### C language standard functions used

* ``write``, ``malloc``, ``free``, ``va_copy``, ``va_start``, ``va_end``, ``va_arg``

## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)

## General info
This project is the first group project of the course of Foundations at Holberton School Peru.
Our goal was to create a program that performs the same functions as "printf", which is a pre-defined function in C language and which is defined under ``‹stdio.h›`` library.

``_printf()``function may be used in any C language program. And this is the prototype:

```
_printf(const char *format, ...)
```

"format" is the string that could contain any number of specifiers folloewd by a '`%`' symbol.

## Technologies
* This Project is created with:
* C version: C90
* GCC version: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Examples

To print a NAME (Yohel) and an AGE (31 years old).

```
#include "main.h"

int age; age = 31;
char *name; name = "Yohel";
\n
printf ( "I am %s and I am %d years old.\n", name, age );
```

We obtain:
```
I am Yohel and I am 31 years old.
```

AUTHORS:
Carlos Soria (https://github.com/Soria-c)
Yohel Cruz (https://github.com/yohelce)
Holberton School Peru - Cohort 17
