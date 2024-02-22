/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_help_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:01:38 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/22 10:13:42 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (0);
	result->content = content;
	result->next = NULL;
	return (result);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	indexing(t_list **a)
{
	t_list	*tmp;
	t_list	*current;

	tmp = *a;
	while (tmp)
	{
		current = *a;
		tmp->index = 0;
		while (current)
		{
			if (tmp->content > current->content)
				tmp->index++;
			current = current->next;
		}
		tmp = tmp->next;
	}
}
