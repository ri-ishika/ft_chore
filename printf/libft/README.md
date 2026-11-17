*This project has been created as part of the 42 curriculum by riishika.*
# libft
C language library, which provides functions to process strings and linked lists.

### Table of contents
- [Description](#description)
	1. [Part 1 - Libc functions](#part-1---libc-functions)
	2. [Part 2 - Additional functions](#part-2---additional-functions)
	3. [Part 3 - Linked list](#part-3---linked-list)
- [Instructions](#instructions)
- [Resources](#resources)

# Description
This library consists of 3 parts of functions, and put them together in **"libft.h"**.

## Part 1 - Libc functions
This part contains functions what I reimplement from the libc.

- **ft_isalpha** - checks for an alphabetic character.
- **ft_isdigit** - checks for a digit (0 through 9).
- **ft_isalnum** - checks for an alphanumeric character.
- **ft_isascii** - checks whether character fits into the ASCII character set.
- **ft_isprint** - checks for any printable character including space.
- **ft_strlen** - calculates the length of the string pointed to.
- **ft_memset** - fills the first "n" bytes of the memory area pointed to.
- **ft_bzero** - erases the data in the n bytes of the memory.
- **ft_memcpy** - copies n bytes from memory area "src" to memory area "dest".
- **ft_memmove** - copies n bytes from memory area "src" to memory area "dest", and doesn't matter with their overlapping.
- **ft_strlcpy** - copies string with memory safety.
- **ft_strlcat** - concatenates string with memory safety.
- **ft_toupper** - converts lowercase letters to uppercase.
- **ft_tolower** - converts uppercase letters to lowercase.
- **ft_strchr** - searches given character from given string, and returns the first of them.
- **ft_strrchr** - searches given character from given string, and returns the last of them.
- **ft_strncmp** - compare first n characters of strings with lexicographical order.
- **ft_memchr** - scans the initial n bytes of the memory area pointed to by given string.
- **ft_memcmp** - compare first n memory, with lexicographical order when considered as unsigned char.
- **ft_strnstr** - locates the first occurrence of the  null-terminated string  little  in  the  string big, where not more than len characters are searched.
- **ft_atoi** - returns a number with representing given string.
- **ft_calloc** - returns a array nullified array with given size.
- **ft_strdup** - returns a copy of given string with memory allocation.

## Part 2 - Additional functions
This part contains functions not included in libc, but process strings.

- **ft_substr** - returns substring from "*s", start from "start" and maximum length of "len"
- **ft_strjoin** - returns a new string, with contatenates given two strings.
- **ft_strtrim** - returns a new string, with given characters are removed from given string.
- **ft_split** - splits given string into words, and returns them in a new string array.
- **ft_itoa** - returns a new string with representing given integer.
- **ft_strmapi** - applies given function to each character of given string, and stores them in new string.
- **ft_striteri** - applies given function to each character of given string, and the character may be changed by the function.
- **ft_putchar_fd** - outputs given character to given file descriptor.
- **ft_putstr_fd** - outputs given string to given file descriptor.
- **ft_putendl_fd** - outputs given string and new line to given file descriptor.
- **ft_putnbr_fd** - outputs given integer to given file descriptor.

## Part 3 - Linked list
This part contains functions to control linked lists.

- **ft_lstnew** - allocates memory and return a new node.
- **ft_lstadd_front** - add given node at the start of the list.
- **ft_lstsize** - counts the number of node in the list.
- **ft_lstlast** - returns the last node of the list.
- **ft_lstadd_back** - adds given node at the end of the list.
- **ft_lstdelone** - frees given node with using given del function.
- **ft_lstclear** - deletes and frees given node.
- **ft_lstiter** - applies given function to contents if node.
- **ft_lstmap** - applies given function to contents of node, and store results in a new list.

## libft.h
In this header file, all of these functions are declared their prototype, and following object-like macros and header files are declared, or included.
- **FALSE** - defined as (int)0
- **TRUE** - defined as (int)1
- **<stdlib.h>** - to use **malloc** function, and type **size_t**.
- **<limits.h>** - to use MAX/MIN size of variables.
- **<stdint.h>** - to use SIZE_MAX.
- **<unistd.h>** - to use **write** function.

# Instructions
If you complie your program with libft.a like this:
```
cc *.o libft.a
```
then you can include all functions in this library by including like this:
```c
#include "libft.h"
```

# Resources
## Referrences
- subject
	https://cdn.intra.42.fr/pdf/pdf/228452/en.subject.pdf
- Japanese man pages of linux
	https://linuxjm.sourceforge.io/
- testers I used made by other 42 students
	https://github.com/Tripouille/libftTester

## AI usage
I used generative AIs for searching informations, generating test code, and considering subject requirement.
