/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:25:31 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/22 12:39:58 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		push_a(a, b);
	else if (flag == 2)
		push_b(a, b);
}
