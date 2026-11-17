/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:34:49 by riishika          #+#    #+#             */
/*   Updated: 2026/10/18 01:12:58 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sub_cmp(const char *big, const char *lit, size_t len, size_t start)
{
	size_t	i;

	i = 0;
	while (start + i < len)
	{
		if (big[i] != lit[i])
			return (0);
		++i;
		if (lit[i] == '\0')
			return (1);
	}
	return (-1);
}

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	int		status;

	if (big == NULL || lit == NULL)
		return (NULL);
	if (*lit == '\0')
		return ((char *)big);
	i = 0;
	while (*big != '\0' && i < len)
	{
		if (*big == *lit)
		{
			status = sub_cmp(big, lit, len, i);
			if (status == 1)
				return ((char *)big);
			if (status == -1)
				break ;
		}
		++big;
		++i;
	}
	return (NULL);
}
