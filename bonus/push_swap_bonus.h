/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:50:09 by aboukdid          #+#    #+#             */
/*   Updated: 2024/02/22 12:46:14 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "get_next_line_bonus.h"

typedef struct s_list
{
	int				content;
	int				index;
	int				size;
	struct s_list	*next;
}				t_list;

long	ft_atoi(char *str);
char	**ft_split(char *s, char c);
char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strncmp(char *s1, char *s2, int n);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	indexing(t_list **a);
void	free_result_array(char **result);
int		is_integer(char *str);
int		check_higher(char *str);
int		check_doubles(char **result);
int		check_empty(char *str);
int		check_is_sorted(t_list **a);
void	do_push(t_list **a, t_list **b, int flag);
void	do_reverse_rotate(t_list **a, t_list **b, int flag);
void	do_rotate(t_list **a, t_list **b, int flag);
void	do_swap(t_list **a, t_list **b, int flag);
int		last_index(t_list **a);
int		check_position(t_list **b, int index);
void	print_error(void);
void	free_stack(t_list **stack);

#endif