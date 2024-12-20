/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:51:57 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/22 16:36:12 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	swap(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	do_swap(t_list **a, t_list **b, int flag)
{
	if (flag == 1)
		swap(a);
	else if (flag == 2)
		swap(a);
	else if (flag == 0)
	{
		swap(a);
		swap(b);
	}
}
