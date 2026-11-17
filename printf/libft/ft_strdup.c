/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:33:38 by riishika          #+#    #+#             */
/*   Updated: 2026/10/19 21:13:50 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len == SIZE_MAX)
		return (NULL);
	dest = malloc(s_len + 1);
	if (dest == NULL)
		return (NULL);
	if (s_len == 0)
	{
		*dest = '\0';
		return (dest);
	}
	ft_strlcpy(dest, s, s_len + 1);
	return (dest);
}
