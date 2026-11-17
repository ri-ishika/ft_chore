/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:33:12 by riishika          #+#    #+#             */
/*   Updated: 2026/10/19 21:08:13 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uc_s;
	size_t				i;

	if (s == NULL)
		return (NULL);
	uc_s = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*uc_s == (unsigned char)c)
			return ((void *)uc_s);
		++uc_s;
		++i;
	}
	return (NULL);
}
