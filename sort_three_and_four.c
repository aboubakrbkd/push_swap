/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_and_four.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:58:12 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/18 16:56:43 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_node(t_list *a)
{
	int	max;

	if (!a)
		return (0);
	max = INT_MIN;
	while (a)
	{
		if (a->content > max)
			max = a->content;
		a = a->next;
	}
	return (max);
}

int	min_node(t_list *a)
{
	int	max;

	if (!a)
		return (0);
	max = INT_MAX;
	while (a)
	{
		if (a->content < max)
			max = a->content;
		a = a->next;
	}
	return (max);
}

void	sort_three(t_list **a)
{
	int	high;

	high = max_node(*a);
	if (high == (*a)->content)
		do_rotate(a, 0, 1);
	else if ((*a)->next->content == high)
		do_reverse_rotate(a, 0, 1);
	if ((*a)->content > (*a)->next->content)
		do_swap(a, 0, 1);
}

void	sort_four(t_list **a, t_list **b)
{
	int	min;

	min = min_node(*a);
	if ((*a)->content == min)
		do_push(a, b, 2);
	else if ((*a)->next->content == min)
	{
		do_rotate(a, 0, 1);
		do_push(a, b, 2);
	}
	else if ((*a)->next->next->content == min)
	{
		do_reverse_rotate(a, 0, 1);
		do_reverse_rotate(a, 0, 1);
		do_push(a, b, 2);
	}
	else if ((*a)->next->next->next->content == min)
	{
		do_reverse_rotate(a, 0, 1);
		do_push(a, b, 2);
	}
	sort_three(a);
	do_push(a, b, 1);
}
