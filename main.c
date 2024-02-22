/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:15:27 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/20 19:31:50 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_result_array(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
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

void	check_argument_and_push(int argc, char **argv, t_list **a)
{
	int		i;
	char	**result;
	char	*joined_arguments;

	i = 0;
	joined_arguments = ft_strjoin(argc - 1, argv + 1, " ");
	result = ft_split(joined_arguments, ' ');
	while (result[i])
	{
		if (is_integer(result[i]) || check_higher(result[i])
			|| check_doubles(result))
		{
			free(joined_arguments);
			free_result_array(result);
			print_error();
		}
		ft_lstadd_back(a, ft_lstnew(ft_atoi(result[i])));
		i++;
	}
	free(joined_arguments);
	free_result_array(result);
}

void	sort_argument(t_list **a, t_list **b)
{
	indexing(a);
	if ((*a)->size == 2 && check_is_sorted(a))
		do_swap(a, 0, 1);
	else if ((*a)->size == 3 && check_is_sorted(a))
		sort_three(a);
	else if ((*a)->size == 4 && check_is_sorted(a))
		sort_four(a, b);
	else if ((*a)->size == 5 && check_is_sorted(a))
		sort_five(a, b);
	else if ((*a)->size > 5 && check_is_sorted(a))
		sort_pivot(a, b);
}

int	main(int argc, char	**argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	if (argc < 2)
		exit(EXIT_FAILURE);
	a = NULL;
	b = NULL;
	i = 0;
	while (argv[i])
	{
		if (check_empty(argv[i]))
			print_error();
		i++;
	}
	check_argument_and_push(argc, argv, &a);
	a->size = ft_lstsize(a);
	sort_argument(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
