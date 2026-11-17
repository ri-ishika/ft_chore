/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:51:30 by riishika          #+#    #+#             */
/*   Updated: 2026/11/14 00:56:20 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	open_fd(const char *file, int *dest_fd)
{
	*dest_fd = open(file, O_RDONLY);
	if (*dest_fd < 0)
	{
		printf("error in opening file: %s\n", file);
		return (FALSE);
	}
	return (TRUE);
}

void	read_file(const char *file, int fd)
{
	size_t	what_line;
	char	*cur_line;

	what_line = 0;
	while (TRUE)
	{
		cur_line = get_next_line(fd);
		if (cur_line == NULL)
			break ;
		printf("%s line %zu : %s", file, what_line, cur_line);
		if (cur_line != NULL)
			free(cur_line);
		what_line++;
	}
	printf("<<<file end>>>\n");
}

int	main(void)
{
	int	readme_fd;
	int	empty_fd;

	if (!open_fd("README.md", &readme_fd))
		return (1);
	if (!open_fd("empty.txt", &empty_fd))
	{
		close(readme_fd);
		return (1);
	}
	printf("---start---\n");
	read_file("README.md", readme_fd);
	read_file("empty.txt", empty_fd);
	printf("----end----\n");
	close(readme_fd);
	close(empty_fd);
	return (0);
}
