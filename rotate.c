/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:52:09 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/20 13:47:37 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **head)
{
	t_list	*top;
	t_list	*bottom;

	if (head == NULL || (*head)->next == NULL)
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
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if (flag == 2)
	{
		rotate(a);
		write(1, "rb\n", 3);
	}
	else if (flag == 0)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
}
