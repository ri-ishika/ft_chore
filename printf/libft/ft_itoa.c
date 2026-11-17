/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:32:41 by riishika          #+#    #+#             */
/*   Updated: 2026/10/17 05:51:12 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_number_bytes(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		n *= -1;
		++count;
	}
	while (n > 0)
	{
		n /= 10;
		++count;
	}
	return (count);
}

static void	itoa_main(int n, char *iter, int bytes)
{
	int	i;

	i = 0;
	iter += bytes;
	*iter-- = '\0';
	while (i < bytes)
	{
		*iter = n % 10 + '0';
		n /= 10;
		--iter;
		++i;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	char	*result_iter;

	if (n == INT_MIN)
	{
		result = malloc(12);
		if (result == NULL)
			return (NULL);
		ft_strlcpy(result, "-2147483648", 12);
	}
	else
	{
		result = malloc(count_number_bytes(n) + 1);
		if (result == NULL)
			return (NULL);
		result_iter = result;
		if (n < 0)
		{
			*result_iter++ = '-';
			n *= -1;
		}
		itoa_main(n, result_iter, count_number_bytes(n));
	}
	return (result);
}
