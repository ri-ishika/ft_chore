/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:34:56 by riishika          #+#    #+#             */
/*   Updated: 2026/10/18 18:51:36 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;

	if (s1 == NULL || *s1 == '\0' || set == NULL)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) != NULL && s1[start] != '\0')
		++start;
	if (start == end + 1)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end]) != NULL)
		--end;
	result = malloc((end - start + 1) + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, &s1[start], end - start + 2);
	return (result);
}
