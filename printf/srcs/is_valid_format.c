/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:56:05 by riishika          #+#    #+#             */
/*   Updated: 2026/10/23 18:27:31 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*skip_int(const char *format)
{
	if (*format == '.')
		++format;
	if (*format == '')
	while (ft_strchr(DEC_CHAR, *format))
		++format;
	return (format);
}

int	is_valid_format(const char *format)
{
	while (ft_strchr(FLAG_CHAR, *format))
		++format;
	if (is_valid_int(format))
		format = skip_int(format);
	if (*format == '.' && is_valid_int(format + 1))
		format = skip_int(format);
	if (ft_strchr(CONV_CHAR, *format))
		return (TRUE);
	else
		return (FALSE);
}
