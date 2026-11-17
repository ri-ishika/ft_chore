#!/bin/bash
cc -Wall -Wextra -Werror -g3 -D BUFFER_SIZE=4096 main.c get_next_line.c get_next_line_utils.c -o test
