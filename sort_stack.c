/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:04:08 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/20 12:06:50 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack_node **stack1, t_stack_node **stack2)
{
	int	len;

	len = stack_size(*stack1);
	if (len-- > 3 && ft_checksorted(*stack1) != 1)
		pb(stack1, stack2);
	if (len-- > 3 && ft_checksorted(*stack1) != 1)
		pb(stack1, stack2);
	while (len > 3 && ft_checksorted(*stack1) != 1)
	{
		init_nodes1(*stack1, *stack2);
		move_a_to_b(stack1, stack2);
		len--;
	}
	sort_three(stack1);
	while (*stack2)
	{
		init_nodes2(*stack1, *stack2);
		move_b_to_a(stack1, stack2);
	}
	current_index(*stack1);
	min_to_top(stack1);
}
