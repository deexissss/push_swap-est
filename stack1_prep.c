/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1_prep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:35:01 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/24 12:38:23 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack -> index = i;
		if (i <= median)
			stack -> sup_median = true;
		else
			stack -> sup_median = false;
		stack = stack -> next;
		i++;
	}
}

void	stack1_target(t_stack_node *stack1, t_stack_node *stack2)
{
	t_stack_node	*current2;
	t_stack_node	*target_node;
	int				best_index;

	while (stack1)
	{
		best_index = INT_MIN;
		current2 = stack2;
		while (current2)
		{
			if (current2 -> data < stack1 -> data
				&& current2 -> data > best_index)
			{
				best_index = current2 -> data;
				target_node = current2;
			}
			current2 = current2 -> next;
		}
		if (best_index == INT_MIN)
			stack1 -> target = get_max(stack2);
		else
			stack1 -> target = target_node;
		stack1 = stack1 -> next;
	}
}

void	cost(t_stack_node *stack1, t_stack_node *stack2)
{
	int	len1;
	int	len2;

	len1 = stack_size(stack1);
	len2 = stack_size(stack2);
	while (stack1)
	{
		stack1 -> cost = stack1 -> index;
		if (!(stack1 -> sup_median))
			stack1 -> cost = len1 - (stack1 -> index);
		if (stack1 -> target -> sup_median)
			stack1 -> cost += stack1 -> target -> index;
		else
			stack1 -> cost += len2 - (stack1 -> target -> index);
		stack1 = stack1 -> next;
	}
}

void	stack1_cheapest(t_stack_node *stack)
{
	int				cheapest_val;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_val = INT_MAX;
	while (stack)
	{
		if (stack -> cost < cheapest_val)
		{
			cheapest_val = stack -> cost;
			cheapest_node = stack;
		}
		stack = stack -> next;
	}
	cheapest_node -> cheapest = true;
}

void	init_nodes1(t_stack_node *stack1, t_stack_node *stack2)
{
	current_index(stack1);
	current_index(stack2);
	stack1_target(stack1, stack2);
	cost(stack1, stack2);
	stack1_cheapest(stack1);
}
