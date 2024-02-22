/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:24:03 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/22 10:19:18 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_higher(char *str)
{
	long	result;

	result = ft_atoi(str);
	if (result > INT_MAX || result < INT_MIN)
		return (1);
	return (0);
}

int	check_doubles(char **result)
{
	int	i;
	int	j;

	i = 0;
	while (result[i])
	{
		j = i + 1;
		while (result[j])
		{
			if (ft_atoi(result[i]) == ft_atoi(result[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_empty(char *str)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			f++;
		i++;
	}
	if (f == i)
		return (1);
	return (0);
}

int	check_is_sorted(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
