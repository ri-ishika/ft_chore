*This project has been created as part of the 42 curriculum by riishika.*
# Get Next Line
A function that returns a line read from a file descriptor.

### Table of contents
- [Description](#description)
	- [get_next_line.c](#get_next_linec)
	- [get_next_line_utils.c](#get_next_line_utilsc)
	- [get_next_line.h](#get_next_lineh)
- [Instructions](#instructions)
- [Test](#test)
- [Resources](#resources)
	- [Referrences](#referrences)
	- [AI usage](#ai-usage)

# Description

## get_next_line.c
This file provides following function. Other functions are used to deploying main logic of it, so I didn't consider them as helper functions.
### char	*get_next_line(int fd);
This function allows you to read one line from file descripter until reading file ends.
If there is nothing to read or an error occurred, this function returns NULL. 

#### null handling
Even though reading file contains null, this function continues to read until file ends, or newline appears. In this case, using return value in functions for strings is not supported.

## get_next_line_utils.c
This file provides helper functions, which is used to help get_next_line.c functions.

## get_next_line.h

### standard headers
This file includes following headers.
|header|contents used in this project|
|---|---|
|<unistd.h>|read(), size_t, NULL|
|<stdlib.h>|malloc(), free()|
|<stdint.h>|SIZE_MAX|

### FALSE, TRUE
FALSE, TRUE are set to 0, 1. I'm afraid of using C99 headers(because restrict keyword, which is introduced in C99 is forbidden in 42 subjects), so I don't use \<stdbool.h\>.

### SYSCALL_MAX
0x7ffff000 is the max size to be handled by read, write, or similer system calls, so I defined it as a macro.

### BUFFER_SIZE
Sets buffer size read by one read. It is set to 4096 by default. In default, page size of Linux is 4096, so default value is set to be aligned to it. Of course you can change this value by -D option, like -D BUFFER_SIZE=42.

### t_line_info (struct s_line_info)
Stores informations for each file descripter by linked list.
|type|name|description|
|---|---|---|
|int|fd|file descripter|
|unsigned char *|buf|buffer with BUFFER_SIZE|
|struct s_fd_info *|next|address of next node|

### t_result (struct s_result)
Stores informations for return value.
|type|name|description|
|---|---|---|
|char *|line|returning line terminated by '\0', may contain '\0'|
|size_t|len|length of line|

# Instructions
You can use this function by compiling with other sources.
```
cc *.c get_next_line.c get_next_line_utils.c
```

# Test

__If you use this test, you must make empty text file named empty.txt__

You can test my code by saving code below as main.c,
and compile with get_next_line.c, and get_next_line_utils.c:
```
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	open_fd(const char *file, int *dest_fd)
{
	*dest_fd = open(file, O_RDONLY);
	if (*dest_fd < 0)
	{
		printf("error in opening file: %s\n", file);
		return (FALSE);
	}
	return (TRUE);
}

void	read_file(const char *file, int fd)
{
	size_t	what_line;
	char	*cur_line;

	what_line = 0;
	while (TRUE)
	{
		cur_line = get_next_line(fd);
		if (cur_line == NULL)
			break ;
		printf("%s line %zu : %s", file, what_line, cur_line);
		free(cur_line);
		what_line++;
	}
	printf("<<<file end>>>\n");
}

int	main(void)
{
	int		readme_fd;
	int		empty_fd;

	if (!open_fd("README.md", &readme_fd))
		return (1);
	if (!open_fd("empty.txt", &empty_fd))
	{
		close(readme_fd);
		return (1);
	}
	printf("---start---\n");
	read_file("README.md", readme_fd);
	read_file("empty.txt", empty_fd);
	printf("----end----\n");
	close(readme_fd);
	close(empty_fd);
	return (0);
}

```

And saving code below as test.sh:
```
#!/bin/bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=4096 main.c get_next_line.c get_next_line_utils.c -o test
valgrind --leak-check=full --show-leak-kinds=all ./test
rm -f ./test
```

Then run this:
```
./test.sh
```

# Resources
## Referrences
- musl implementation of getdelim
	https://github.com/esmil/musl/blob/master/src/stdio/getdelim.c
- musl implementation of getc_unlocked
	https://github.com/esmil/musl/blob/master/src/internal/stdio_impl.h
- explanation of this project (I didn't read latter section)
	https://zenn.dev/grigri_grin/articles/bf45a9fa50f25f
- man page, translated to Japanese
	https://linuxjm.sourceforge.io

## AI usage
I used generative AI for searching information, and considering subject requirement.


#### One last thing:
testing not newline terminated file-> 