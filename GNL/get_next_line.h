/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:46:55 by riishika          #+#    #+#             */
/*   Updated: 2026/11/15 09:56:44 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# define FALSE 0
# define TRUE 1
# define SYSCALL_MAX 0x7ffff000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_fd_info
{
	int					fd;
	unsigned char		buf[BUFFER_SIZE];
	unsigned char		*buf_start;
	struct s_fd_info	*next;
}	t_fd_info;

typedef struct s_result
{
	char	*line;
	size_t	pos;
	size_t	len;
	ssize_t	return_bytes;
}	t_result;

char		*get_next_line(int fd);

void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_realloc(void *ptr, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
ssize_t		free_line(t_result *result, ssize_t bytes);
t_fd_info	*info_alloc(int fd);

#endif
