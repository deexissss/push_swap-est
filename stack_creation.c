/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:35:24 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/24 12:15:29 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack -> cheapest)
			return (stack);
		stack = stack -> next;
	}
	return (NULL);
}

void	node_to_top(t_stack_node **stack, t_stack_node *top_node,
		char c_stack)
{
	while (*stack != top_node)
	{
		if (c_stack == 'a')
		{
			if (top_node -> sup_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (c_stack == 'b')
		{
			if (top_node -> sup_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
