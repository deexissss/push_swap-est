/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2_prep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:19:04 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/24 12:38:36 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack2_target(t_stack_node *stack1, t_stack_node *stack2)
{
	t_stack_node	*current1;
	t_stack_node	*target_node;
	int				best_index;

	while (stack2)
	{
		best_index = INT_MAX;
		current1 = stack1;
		while (current1)
		{
			if (current1 -> data > stack2 -> data
				&& current1 -> data < best_index)
			{
				best_index = current1 -> data;
				target_node = current1;
			}
			current1 = current1 -> next;
		}
		if (best_index == INT_MAX)
			stack2 -> target = get_min(stack1);
		else
			stack2 -> target = target_node;
		stack2 = stack2 -> next;
	}
}

void	init_nodes2(t_stack_node *stack1, t_stack_node *stack2)
{
	current_index(stack1);
	current_index(stack2);
	stack2_target(stack1, stack2);
}
