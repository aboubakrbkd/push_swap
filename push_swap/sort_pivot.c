/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:31:54 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/20 13:32:33 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_pivot(t_list **a, t_list **b)
{
	int	lp1;
	int	p1;
	int	p2;

	lp1 = -1;
	p1 = ft_lstsize(*a) / 3;
	p2 = ft_lstsize(*a) / 6 ;
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->index < p1)
			do_push(a, b, 2);
		else
			do_rotate(a, 0, 1);
		if (ft_lstsize(*b) > 1 && ((*b)->index >= lp1 && (*b)->index <= p2))
			do_rotate(b, 0, 2);
		if (ft_lstsize(*b) == p1)
		{
			lp1 = p1;
			p1 += ft_lstsize(*a) / 3;
			p2 = ft_lstsize(*a) / 6 + lp1;
		}
	}
	sort_three(a);
	sort_pivot_helper(a, b);
}

void	if_is_up(t_list **a, t_list **b, int *last_one, int biggest_index)
{
	while ((*a)->index - 1 != (*b)->index)
	{
		if ((*b)->index > *last_one || biggest_index == *last_one)
		{
			do_push(a, b, 1);
			do_rotate(a, 0, 1);
			*last_one = last_index(a);
		}
		else
			do_rotate(b, 0, 2);
	}
	do_push(a, b, 1);
}

void	if_is_down(t_list **a, t_list **b, int *last_one, int biggest_index)
{
	while ((*a)->index - 1 != (*b)->index)
	{
		if ((*b)->index > *last_one || biggest_index == *last_one)
		{
			do_push(a, b, 1);
			do_rotate(a, 0, 1);
			*last_one = last_index(a);
		}
		else
			do_reverse_rotate(b, 0, 2);
	}
	do_push(a, b, 1);
}

void	sort_pivot_helper(t_list **a, t_list **b)
{
	int	biggest_index;
	int	last_one;

	biggest_index = last_index(a);
	last_one = last_index(a);
	while (*b)
	{
		if (check_position(b, (*a)->index - 1) == 0)
			if_is_up(a, b, &last_one, biggest_index);
		else if (check_position(b, (*a)->index - 1) == -1)
			if_is_down(a, b, &last_one, biggest_index);
		while (*b && (*a)->index - 1 == (*b)->index)
			do_push(a, b, 1);
		while (last_index(a) == (*a)->index - 1)
		{
			do_reverse_rotate(a, 0, 1);
			last_one = last_index(a);
		}
	}
}
