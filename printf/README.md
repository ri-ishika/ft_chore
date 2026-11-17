This project has been created as part of the 42 curriculum by riishika.
# ft_printf
This is my reimplementation of printf.

### Table of contents
- [Description](#description)
	1. [Part 1 - Libc functions](#part-1---libc-functions)
	2. [Part 2 - Additional functions](#part-2---additional-functions)
	3. [Part 3 - Linked list](#part-3---linked-list)
- [Instructions](#instructions)
- [Resources](#resources)

# Description
## printf
### int printf(const char *format, ...);
- behaves same as ft_vprintf() without ap from va_start(ap, format) is passed.

## dprintf
### int	ft_dprintf(int fd, const char *format, ...);
- behaves same as ft_vdprintf() without it only outputs to stdout.

## vprintf
### int	ft_vprintf(const char *format, va_list ap);
- behaves same as ft_vdprintf() without it only outputs to stdout.

## vdprintf
### int	ft_vdprintf(int fd, const char *format, va_list ap);
- 

# Instructions

# Resources
## Referrences
- how to import another makefile
	https://tex2e.github.io/blog/makefile/import-another-makefile
- man page of printf like functions, translated to Japanese
	https://linuxjm.sourceforge.io/html/LDP_man-pages/man3/printf.3.html
- man page of va_... macros, translated to Japanese
	https://nxmnpg.lemoda.net/ja/3/va_start
- musl implementation of printf
	https://git.musl-libc.org/cgit/musl/tree/src/stdio/printf.c
- musl implementation of vfprintf
	https://git.musl-libc.org/cgit/musl/tree/src/stdio/vfprintf.c
- usage of va_... macros (partly printf specific)
	https://qiita.com/subaruf/items/657c67a1809515589a7c

## AI usage
I used generative AI for searching information from Google.
