/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:34:59 by riishika          #+#    #+#             */
/*   Updated: 2026/10/18 20:58:47 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;

	count = 0;
	while (count < len && s[start + count] != '\0')
		++count;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		result = malloc(1);
		*result = '\0';
		return (result);
	}
	result = malloc(count_substr(s, start, len) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		result[i] = s[start + i];
		++i;
	}
	result[i] = '\0';
	return (result);
}
