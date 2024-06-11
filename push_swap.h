/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:11:08 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/11 15:22:52 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_stack_node
{
	int					data;
	int					index;
	int					cost;
	bool				sup_median;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/*stack utils*/

t_stack_node	*create_new_node(int data);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			init_stack(t_stack_node *stack);
int				is_empty(t_stack_node **stack);
int				ft_remove(t_stack_node **stack);
int				stack_size(t_stack_node *stack);
int				ft_isdigit(int c);
t_stack_node	*get_last_node(t_stack_node *stack);
void			add_node(t_stack_node **stack, int data);
void			display_stack(t_stack_node *stack);
int				ft_stacklast(t_stack_node *stack);
t_stack_node	*get_min(t_stack_node *stack);
t_stack_node	*get_max(t_stack_node *stack);

/*check utils*/

int				ft_checksorted(t_stack_node **stack);
int				syntax_error(char *str);
int				duplicate_nb(t_stack_node *stack, int nb);
void			free_stack(t_stack_node *stack);
void			error(t_stack_node *stack);

/*operations*/

void			pa(t_stack_node **stacka, t_stack_node **stackb);
void			pb(t_stack_node **stacka, t_stack_node **stackb);
void			sa(t_stack_node **stack);
void			sb(t_stack_node **stack);
void			ss(t_stack_node **stacka, t_stack_node **stackb);
void			ra(t_stack_node **stack);
void			rb(t_stack_node **stack);
void			rr(t_stack_node **stacka, t_stack_node **stackb);
void			rra(t_stack_node **stack);
void			rrb(t_stack_node **stack);
void			rrr(t_stack_node **stacka, t_stack_node **stackb);
void			both_rotate(t_stack_node **stack1, t_stack_node **stack2,
					t_stack_node *cheapest);
void			both_rotate_reverse(t_stack_node **stack1,
					t_stack_node **stack2, t_stack_node *cheapest);
/*sort utils*/

void			init_nodes1(t_stack_node *stack1, t_stack_node *stack2);
void			init_nodes2(t_stack_node *stack1, t_stack_node *stack2);
void			current_index(t_stack_node *stack);
void			sort_preparation(t_stack_node **stack, t_stack_node *top_node,
					char c_stack);
void			stack1_creation(t_stack_node **stack, char **argv);
void			sort_three(t_stack_node **stack);

#endif
