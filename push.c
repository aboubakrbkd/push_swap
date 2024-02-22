/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:25:31 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/22 11:35:26 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list **a, t_list **b)
{
	t_list	*top_a;

	if (b == NULL || *a == NULL)
		return ;
	top_a = *a;
	*a = top_a->next;
	top_a->next = *b;
	*b = top_a;
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*top_b;

	if (b == NULL || *b == NULL)
		return ;
	top_b = *b;
	*b = top_b->next;
	top_b->next = *a;
	*a = top_b;
}

void	do_push(t_list **a, t_list **b, int flag)
{
	if (flag == 1)
	{
		push_a(a, b);
		write(1, "pa\n", 3);
	}
	else if (flag == 2)
	{
		push_b(a, b);
		write(1, "pb\n", 3);
	}
}
