/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:32:19 by riishika          #+#    #+#             */
/*   Updated: 2026/10/18 20:54:34 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	unsigned char	*result;

	if (number * size == 0)
	{
		result = malloc(1);
		if (result == NULL)
			return (NULL);
		*result = '\0';
		return (result);
	}
	if (number > SIZE_MAX / size)
		return (NULL);
	result = malloc(number * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, number * size);
	return ((void *)result);
}
