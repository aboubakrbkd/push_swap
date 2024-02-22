/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:52:09 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/22 16:35:11 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(t_list **head)
{
	t_list	*top;
	t_list	*bottom;

	if (!*head || !(*head)->next)
		return ;
	top = *head;
	bottom = ft_lstlast(top);
	bottom->next = *head;
	*head = top->next;
	top->next = NULL;
}

void	do_rotate(t_list **a, t_list **b, int flag)
{
	if (flag == 1)
		rotate(a);
	else if (flag == 2)
		rotate(a);
	else if (flag == 0)
	{
		rotate(a);
		rotate(b);
	}
}
