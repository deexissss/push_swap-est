/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:17:21 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/11 14:23:51 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*create_new_node(int data)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
	{
		ft_printf("memory allocation failed \n");
		exit(1);
	}
	new_node -> data = data;
	new_node -> next = NULL;
	return (new_node);
}

void	init_stack(t_stack_node *stack)
{
	stack = NULL;
}

int	is_empty(t_stack_node **stack)
{
	if (*stack == NULL)
		return (1);
	return (0);
}

int	ft_remove(t_stack_node **stack)
{
	t_stack_node	*temp;
	int				top_data;

	if (is_empty(stack))
	{
		ft_printf("Pile vide");
		return (-1);
	}
	temp = *stack;
	top_data = temp -> data;
	*stack = (*stack)-> next;
	free(temp);
	return (top_data);
}

int	stack_size(t_stack_node *stack)
{
	int		i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack -> next;
		i++;
	}
	return (i);
}
