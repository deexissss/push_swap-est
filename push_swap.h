#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_stack_node
{
	int					data;
	int					index;
	int					cost;
	bool				median;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/*stack utils*/
t_stack_node	*create_new_node(int data);
void	init_stack(t_stack *stack);
int	is_empty(t_stack *stack);
int	ft_remove(t_stack_node *stack);
int	stack_size(t_stack_node *stack);
t_stack_node	*get_last_node(t_stack_node *stack);
void	add_node(t_stack_node *stack, int data);
void	display_stack(t_stack_node *stack);
int	ft_stacklast(t_stack_node *stack);
t_stack_node	*get_min(t_stack_node *stack);
t_stack_node	*get_max(t_stack_node *stack);

/*check utils*/
int	ft_checksorted(t_stack_node *stack);
int	syntax_error(char *str);
int	duplicate_nb(t_stack_node *stack, int nb);
void	free_stack(t_stack_node *stack);
void	error(t_stack_node *stack);

/*operations*/

void    pa(t_stack_node *stacka, t_stack_node *stackb);
void    pb(t_stack_node *stacka, t_stack_node *stackb);
void    sa(t_stack_node *stack);
void    sb(t_stack_node *stack);
void    ss(t_stack_node *stacka, t_stack_node *stackb);
void    ra(t_stack_node *stack);
void    rb(t_stack_node *stack);
void    rr(t_stack_node *stacka, t_stack_node *stackb);
void    rra(t_stack_node *stack);
void    rrb(t_stack_node *stack);
void    rrr(t_stack_node *stacka, t_stack_node *stackb);


#endif
