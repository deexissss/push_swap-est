/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg.lu>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:54:38 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/10 22:03:42 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*create_new_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		ft_printf("memory allocation failed \n");
		exit(1);
	}
	new_node -> data = data;
	new_node -> next = NULL;
	return (new_node);
}

void	init_stack(t_stack *stack)
{
	stack -> top = NULL;
}

int	is_empty(t_stack *stack)
{
	if (stack -> top == NULL)
		return (1);
	return (0);
}

int	ft_remove(t_stack_node *stack)
{
	t_stack_node	*temp;
	int		top_data;

	if (is_empty(stack))
	{
		ft_printf("Pile vide");
		return (-1);
	}
	temp = stack -> top;
	top_data = temp -> data;
	stack -> top = stack -> top -> next;
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

t_stack_node	*get_last_node(t_stack_node *stack)
{
	while (stack != NULL && stack -> next != NULL)
		stack = stack -> next;
	return (stack);
}

void	add_node(t_stack_node *stack, int data)
{
	t_stack_node	*new_node;

	new_node = create_new_node(data);
	if (new_node == NULL)
		return ;
	if (is_empty(stack))
		stack -> top = new_node;
	else
	{
		while (stack -> next != NULL)
			stack = stack -> next;
		stack -> next = new_node;
	}
}

void	display_stack(t_stack_node *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d\n", stack -> data);
		stack = stack -> next;
	}
}

int	ft_stacklast(t_stack_node *stack)
{
	if (stack -> top == NULL)
		return (0);
	while (stack -> next != NULL)
		stack = sack -> next;
	return (stack -> data);
}
