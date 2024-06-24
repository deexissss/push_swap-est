/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:10:37 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/24 12:16:24 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rr(t_stack_node **stack1, t_stack_node **stack2,
		t_stack_node *cheapest)
{
	while (*stack2 != cheapest -> target && *stack1 != cheapest)
		rr(stack1, stack2);
	current_index(*stack1);
	current_index(*stack2);
}

void	execute_rrr(t_stack_node **stack1, t_stack_node **stack2,
		t_stack_node *cheapest)
{
	while (*stack2 != cheapest -> target && *stack1 != cheapest)
		rrr(stack1, stack2);
	current_index(*stack1);
	current_index(*stack2);
}

void	push_a_to_b(t_stack_node **stack1, t_stack_node **stack2)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*stack1);
	if (cheapest -> sup_median && cheapest -> target -> sup_median)
		execute_rr(stack1, stack2, cheapest);
	else if (!(cheapest -> sup_median) && !(cheapest -> target -> sup_median))
		execute_rrr(stack1, stack2, cheapest);
	node_to_top(stack1, cheapest, 'a');
	node_to_top(stack2, cheapest -> target, 'b');
	pb(stack1, stack2);
}

void	push_b_to_a(t_stack_node **stack1, t_stack_node **stack2)
{
	node_to_top(stack1, (*stack2)-> target, 'a');
	pa(stack1, stack2);
}
