/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:30:15 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/22 12:40:11 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	last_index(t_list **a)
{
	int		flag;
	t_list	*tmp;

	flag = 0;
	tmp = (*a);
	while (tmp->next)
		tmp = tmp->next;
	flag = tmp->index;
	return (flag);
}

int	check_position(t_list **b, int index)
{
	t_list	*tmp;
	int		i;
	int		total;
	int		result;

	i = 0;
	tmp = *b;
	total = (ft_lstsize(*b) / 2);
	while (tmp)
	{
		if (tmp->index == index)
			break ;
		tmp = tmp->next;
		i++;
	}
	result = (total - i);
	if (result <= 0)
		return (-1);
	return (0);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*temp;

	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}