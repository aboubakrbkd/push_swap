/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:19:38 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/20 13:48:46 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				size;
	struct s_list	*next;
}				t_list;

int		last_index(t_list **a);
char	**ft_split(char *s, char c);
long	ft_atoi(char *str);
char	*ft_strjoin(int size, char **strs, char *sep);
int		is_integer(char *str);
int		check_higher(char *str);
int		check_doubles(char **result);
int		check_empty(char *str);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	sort_three(t_list **a);
void	do_rotate(t_list **a, t_list **b, int flag);
void	do_reverse_rotate(t_list **a, t_list **b, int flag);
void	do_swap(t_list **a, t_list **b, int flag);
void	do_push(t_list **a, t_list **b, int flag);
int		check_is_sorted(t_list **a);
int		max_node(t_list *a);
void	sort_four(t_list **a, t_list **b);
int		min_node(t_list *a);
void	sort_five(t_list **a, t_list **b);
void	indexing(t_list **a);
void	sort_pivot(t_list **a, t_list **b);
int		check_position(t_list **b, int index);
int		last_index(t_list **a);
void	print_error(void);
void	sort_pivot_helper(t_list **a, t_list **b);
void	if_is_down(t_list **a, t_list **b, int *last_one, int biggest_index);
void	if_is_up(t_list **a, t_list **b, int *last_one, int biggest_index);

#endif
