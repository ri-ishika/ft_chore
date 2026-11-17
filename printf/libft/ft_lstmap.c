/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riishika <riishika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:33:05 by riishika          #+#    #+#             */
/*   Updated: 2026/10/18 21:22:48 by riishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*result;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	current = ft_lstnew(f(lst->content));
	if (current == NULL)
		return (NULL);
	result = current;
	while (lst->next != NULL)
	{
		lst = lst->next;
		current->next = ft_lstnew(f(lst->content));
		if (current->next == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		current = current->next;
	}
	return (result);
}
