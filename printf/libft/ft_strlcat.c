/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:34:07 by riishika          #+#    #+#             */
/*   Updated: 2026/10/19 21:16:25 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;

	if (dst == NULL)
		return (ft_strlen(src));
	if (src == NULL)
		return (ft_strlen(dst));
	if (size == 0)
		return (size + ft_strlen(src));
	i = 0;
	while (i < size && dst[i] != '\0')
		++i;
	if (i == size)
		return (size + ft_strlen(src));
	dst_size = i;
	i = 0;
	while (src[i] != '\0' && i < size - dst_size - 1)
	{
		dst[i + dst_size] = src[i];
		++i;
	}
	dst[i + dst_size] = '\0';
	return (dst_size + ft_strlen(src));
}
