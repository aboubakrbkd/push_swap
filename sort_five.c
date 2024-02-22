/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:17:11 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/15 20:30:12 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_five_helper(t_list **a, t_list **b, int min)
{
	if ((*a)->content == min)
		do_push(a, b, 2);
	else if ((*a)->next->content == min)
	{
		do_rotate(a, 0, 1);
		do_push(a, b, 2);
	}
	else if ((*a)->next->next->content == min)
	{
		do_rotate(a, 0, 1);
		do_rotate(a, 0, 1);
		do_push(a, b, 2);
	}
	else if ((*a)->next->next->next->content == min)
	{
		do_reverse_rotate(a, 0, 1);
		do_reverse_rotate(a, 0, 1);
		do_push(a, b, 2);
	}
	else if ((*a)->next->next->next->next->content == min)
	{
		do_reverse_rotate(a, 0, 1);
		do_push(a, b, 2);
	}
}

void	sort_five(t_list **a, t_list **b)
{
	int	min;

	min = min_node(*a);
	sort_five_helper(a, b, min);
	sort_four(a, b);
	do_push(a, b, 1);
}
