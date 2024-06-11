/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg.lu>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:03:07 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/11 09:17:11 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack -> data < min)
		{
			min = stack -> data;
			min_node = stack;
		}
		stack = stack -> next;
	}
	return (min_node);
}

t_stack_node	*get_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack -> data > max)
		{
			max = stack -> data;
			max_node = stack;
		}
		stack = stack -> next;
	}
	return (max_node);
}
