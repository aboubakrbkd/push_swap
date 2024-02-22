/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:05:58 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/22 16:35:22 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_list	*find_before_last_node(t_list *head)
{
	while (head->next->next != NULL)
		head = head->next;
	return (head);
}

static void	reverse_rotate(t_list **head)
{
	t_list	*before_last;

	if (!*head || !(*head)->next)
		return ;
	before_last = find_before_last_node(*head);
	before_last->next->next = *head;
	*head = before_last->next;
	before_last->next = NULL;
}

void	do_reverse_rotate(t_list **a, t_list **b, int flag)
{
	if (flag == 1)
		reverse_rotate(a);
	else if (flag == 2)
		reverse_rotate(a);
	else if (flag == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}
