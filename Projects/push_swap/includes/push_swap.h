/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:02:22 by alopes            #+#    #+#             */
/*   Updated: 2021/09/15 10:13:33 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<limits.h>

typedef struct s_list
{
	int				index;
	char			*binary;
	int				len;
	struct s_list	*next;
}	t_list;

long int	ft_atoi_long(const char *nptr);
int			ft_check_repeat(int *ar, int size);
t_list		*ft_initialize_stack(int **args, int **order, int size);
int			ft_get_index(int num, int order[]);
void		ft_sort_int_tab(int tab[], int size);
t_list		*ft_new_element(int num, int order[]);
char		*ft_to_binary(int n);
void		ft_lstadd_front(t_list **list, t_list *new);
void		ft_lstadd_back(t_list **list, t_list *new);
t_list		*ft_lstlast(t_list *lst);
void		ft_swap(t_list **stack);
void		ft_rotate(t_list **stack);
void		ft_rev_rotate(t_list **stack);
void		ft_push(t_list **start, t_list **dest);
int			ft_is_ordered(t_list *stack);
int			ft_max_len(t_list *stack_a);
void		ft_radix_sort(t_list **stack_a, int maxlen, int size);
void		ft_sort_small(t_list **stack_a, int size);
void		ft_perform_rotation(t_list **stack_a, t_list *ptr, int mark,
				int size);
char		**ft_split(char const *s, char c);
int			ft_nword(char const *s, char c);
void		ft_free_split(char **argv);
void		ft_free_stack(t_list **stack);
void		ft_free_array(int *args, int *order);
void		ft_merge(t_list **stack_a, t_list **stack_b, int *min,
				int *max);
#endif
