/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:46:38 by riishika          #+#    #+#             */
/*   Updated: 2026/11/17 19:23:13 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*uc_dest;
	const unsigned char	*uc_src;
	size_t				i;

	uc_dest = (unsigned char *)dest;
	uc_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		uc_dest[i] = uc_src[i];
		i++;
	}
	return (dest);
}

void	*ft_realloc(void *ptr, size_t size)
{
	unsigned char	*result;

	if (size == 0)
	{
		result = malloc(1);
		if (result == NULL)
			return (NULL);
		return (result);
	}
	result = malloc(size);
	if (result == NULL)
		return (NULL);
	if (ptr != NULL)
		ft_memcpy(result, ptr, size);
	return ((void *)result);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uc_s;
	unsigned char		uc_c;
	size_t				i;

	uc_s = (const unsigned char *)s;
	uc_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*uc_s == uc_c)
			return ((void *)uc_s);
		uc_s++;
		i++;
	}
	return (NULL);
}

ssize_t	free_line(t_result *result, ssize_t bytes)
{
	free(result->line);
	return (bytes);
}

t_fd_info	*info_alloc(int fd)
{
	t_fd_info	*new_info;

	new_info = malloc(sizeof(t_fd_info));
	if (new_info == NULL)
		return (NULL);
	new_info->fd = fd;
	new_info->next = NULL;
	new_info->buf_start = new_info->buf;
	return (new_info);
}
