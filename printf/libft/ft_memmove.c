/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:33:18 by riishika          #+#    #+#             */
/*   Updated: 2026/10/18 20:23:18 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*uc_dest;
	const unsigned char	*uc_src;

	if (dest == NULL || src == NULL)
		return (dest);
	if (dest < src || dest >= src + n)
		return (ft_memcpy(dest, src, n));
	uc_dest = (unsigned char *)dest;
	uc_src = (const unsigned char *)src;
	while (n--)
		uc_dest[n] = uc_src[n];
	return (dest);
}
