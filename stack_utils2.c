/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg.lu>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:54:38 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/24 13:47:17 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_last_node(t_stack_node *stack)
{
	while (stack != NULL && stack -> next != NULL)
		stack = stack -> next;
	return (stack);
}

void	add_node(t_stack_node **stack, int data)
{
	t_stack_node	*new_node;
	t_stack_node	*current;

	new_node = create_new_node(data);
	if (new_node == NULL)
		return ;
	if (is_empty(stack))
		*stack = new_node;
	else
	{
		current = *stack;
		while (current -> next != NULL)
			current = current -> next;
		current -> next = new_node;
		new_node -> prev = current;
	}
}

int	ft_stacklast(t_stack_node *stack)
{
	if (stack == NULL)
		return (0);
	while (stack -> next != NULL)
		stack = stack -> next;
	return (stack -> data);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
