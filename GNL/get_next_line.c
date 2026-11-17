/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:46:16 by riishika          #+#    #+#             */
/*   Updated: 2026/11/17 19:23:02 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_fd_info	*find_info(t_fd_info **infos, int fd)
{
	t_fd_info	*cur_info;
	t_fd_info	*new_info;

	cur_info = *infos;
	new_info = info_alloc(fd);
	if (new_info == NULL)
		return (NULL);
	if (cur_info == NULL)
	{
		cur_info = new_info;
		return (cur_info);
	}
	while (cur_info != NULL)
	{
		if (cur_info->fd == fd)
			break ;
		if (cur_info->next == NULL)
			cur_info->next = new_info;
		cur_info = cur_info->next;
	}
	return (cur_info);
}

static int	put_buf_full(t_fd_info *info, t_result *result, ssize_t read_bytes)
{
	result->return_bytes += read_bytes;
	result->line = ft_realloc(result->line, result->return_bytes);
	if (result->line == NULL)
		return (FALSE);
	ft_memcpy(result->line + result->pos, info->buf_start, read_bytes);
	result->pos += read_bytes;
	info->buf_start = info->buf;
	return (TRUE);
}

static int	put_buf_delim(t_fd_info *info, t_result *result,
	ssize_t read_bytes, unsigned char *delim_pos)
{
	size_t	current_bytes;

	current_bytes = info->buf - delim_pos;
	result->return_bytes += current_bytes;
	result->line = ft_realloc(result->line, result->return_bytes + 1);
	if (result->line == NULL)
		return (FALSE);
	ft_memcpy(result->line + result->pos, info->buf_start, read_bytes);
	result->pos += current_bytes + 1;
	result->line[result->pos] = '\0';
	info->buf_start = delim_pos;
	return (TRUE);
}

static ssize_t	ft_getdelim(t_fd_info *info, t_result *result,
	unsigned char delim)
{
	unsigned char	*delim_pos;
	ssize_t			read_bytes;

	read_bytes = 0;
	while (TRUE)
	{
		read_bytes = read(info->fd, info->buf, BUFFER_SIZE);
		if (read_bytes <= 0)
			return (-1);
		delim_pos = ft_memchr(info->buf, delim, BUFFER_SIZE);
		printf("before put\n");
		if (delim_pos == NULL)
		{
			printf("full\n");
			if (!put_buf_full(info, result, read_bytes))
				return (-1);
			continue ;
		}
		else
		{
			printf("delim\n");
			if (!put_buf_delim(info, result, read_bytes, delim_pos))
				return (-1);
			break ;
		}
	}
	return (result->return_bytes);
}

char	*get_next_line(int fd)
{
	static t_fd_info	*infos;
	t_fd_info			*cur_info;
	t_result			result;
	ssize_t				bytes;

	if (BUFFER_SIZE <= 0 || SYSCALL_MAX < BUFFER_SIZE || fd < 0)
		return (NULL);
	cur_info = find_info(&infos, fd);
	if (cur_info == NULL)
		return (NULL);
	result.line = NULL;
	result.pos = 0;
	result.len = 0;
	result.return_bytes = 0;
	printf("before delim\n");
	bytes = ft_getdelim(cur_info, &result, '\n');
	if (bytes < 0 || ft_memchr(result.line, '\0', result.return_bytes - 1))
	{
		free(result.line);
		return (NULL);
	}
	return (result.line);
}
