/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:10:37 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/11 15:21:36 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_rotate(t_stack_node **stack1, t_stack_node **stack2,
		t_stack_node *cheapest)
{
	while (*stack2 != cheapest -> target && *stack1 != cheapest)
		rr(stack1, stack2);
	current_index(*stack1);
	current_index(*stack2);
}

void	both_rotate_reverse(t_stack_node **stack1, t_stack_node **stack2,
		t_stack_node *cheapest)
{
	while (*stack2 != current -> target && *stack1 != cheapest)
		rrr(stack1, stack2);
	current_index(*stack1);
	current_index(*stack2);
}
