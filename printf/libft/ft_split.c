/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:33:33 by riishika          #+#    #+#             */
/*   Updated: 2026/10/17 02:48:08 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			++i;
		if (s[i] != '\0')
		{
			++count;
			while (s[i] != c && s[i] != '\0')
				++i;
		}
	}
	return (count);
}

static char	*word_dup(char const *s, char c, size_t begin)
{
	char	*result;
	size_t	i;
	size_t	word_size;

	word_size = 0;
	while (s[begin + word_size] != c && s[begin + word_size] != '\0')
		++word_size;
	result = malloc(word_size + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[begin + i] != c && s[begin + i] != '\0')
	{
		result[i] = s[begin + i];
		++i;
	}
	result[i] = '\0';
	return (result);
}

static void	*free_when_error(char **result, size_t what_word)
{
	if (what_word == 0)
	{
		free(result);
		return (NULL);
	}
	--what_word;
	while (what_word > 0)
	{
		free(result[what_word]);
		--what_word;
	}
	free(result[what_word]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	what_word;

	i = 0;
	what_word = 0;
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (result == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			++i;
		if (s[i] != '\0')
		{
			result[what_word] = word_dup(s, c, i);
			if (result[what_word] == NULL)
				return (free_when_error(result, what_word));
			++what_word;
			while (s[i] != c && s[i] != '\0')
				++i;
		}
	}
	result[what_word] = NULL;
	return (result);
}
