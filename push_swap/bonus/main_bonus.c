/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:05:48 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/22 10:13:55 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	do_movement(t_list **a, t_list **b, char *op)
{
	if (!ft_strncmp(op, "sa\n", 3))
		do_swap(a, 0, 1);
	else if (!ft_strncmp(op, "sb\n", 3))
		do_swap(b, 0, 2);
	else if (!ft_strncmp(op, "ss\n", 3))
		do_swap(a, b, 0);
	else if (!ft_strncmp(op, "pa\n", 3))
		do_push(a, b, 1);
	else if (!ft_strncmp(op, "pb\n", 3))
		do_push(a, b, 2);
	else if (!ft_strncmp(op, "ra\n", 3))
		do_rotate(a, 0, 1);
	else if (!ft_strncmp(op, "rb\n", 3))
		do_rotate(b, 0, 2);
	else if (!ft_strncmp(op, "rr\n", 3))
		do_rotate(a, b, 0);
	else if (!ft_strncmp(op, "rra\n", 4))
		do_reverse_rotate(a, 0, 1);
	else if (!ft_strncmp(op, "rrb\n", 4))
		do_reverse_rotate(b, 0, 2);
	else if (!ft_strncmp(op, "rrr\n", 4))
		do_reverse_rotate(a, b, 0);
	else
		print_error();
}

void	final_check(t_list *a, t_list *b)
{
	if (!check_is_sorted(&a) && ft_lstsize(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char	**argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
	char	*result;

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
	result = get_next_line(0);
	while (result)
	{
		do_movement(&a, &b, result);
		result = get_next_line(0);
	}
	final_check(a, b);
	return (0);
}
