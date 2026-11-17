/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 22:39:51 by riishika          #+#    #+#             */
/*   Updated: 2026/11/16 03:03:01 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAG_CHAR "#- +0"
# define DEC_CHAR "0123456789"
# define HEX_CHAR "0123456789ABCDEF"
# define CONV_CHAR "cspdiuxX%"

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flag
{
	int				type_change;
	int				zero_fill;
	int				left_align;
	int				put_space;
	int				place_sign;
	int				width;
	int				accuracy;
}	t_flag;

typedef enum e_type
{
	CHR,
	STR,
	PTR,
	INT,
	HEX_LO,
	HEX_UP
}	t_type;

int	ft_printf(const char *str, ...);

// these functions inside in srcs
int	ft_putchar_count_fd(char c, int fd);
int	is_valid_format(const char *format);


#endif
