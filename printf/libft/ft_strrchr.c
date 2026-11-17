/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:34:53 by riishika          #+#    #+#             */
/*   Updated: 2026/10/19 21:18:55 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		++s;
		++i;
	}
	while (i > 0)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		--s;
		--i;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
