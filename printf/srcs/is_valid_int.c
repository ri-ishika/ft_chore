/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 16:40:05 by riishika          #+#    #+#             */
/*   Updated: 2026/10/25 00:09:09 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid_int(const char *format)
{
	long	num;

	if (!ft_isdigit(*format))
		return (FALSE);
	
	num = 0;
}
