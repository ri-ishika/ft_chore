/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:33:16 by riishika          #+#    #+#             */
/*   Updated: 2026/10/18 19:21:15 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*uc_dest;
	const unsigned char	*uc_src;
	size_t				i;

	if (dest == NULL || src == NULL)
		return (dest);
	uc_dest = (unsigned char *)dest;
	uc_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		uc_dest[i] = uc_src[i];
		++i;
	}
	return (dest);
}
