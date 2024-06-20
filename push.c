/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg.lu>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:14:26 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/20 11:34:53 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack_node **stack1, t_stack_node **stack2)
{
	t_stack_node	*node;

	node = *stack1;
	*stack1 = (*stack1)-> next;
	if (*stack1)
		(*stack1)-> prev = NULL;
	node -> prev = NULL;
	if (!*stack2)
	{
		*stack2 = node;
		node -> next = NULL;
	}
	else
	{
		node -> next = *stack2;
		(*stack2)-> prev = node;
		*stack2 = node;
	}
}

void	pa(t_stack_node **stacka, t_stack_node **stackb)
{
	ft_push(stackb, stacka);
	ft_printf("pa\n");
}

void	pb(t_stack_node **stacka, t_stack_node **stackb)
{
	ft_push(stacka, stackb);
	ft_printf("pb\n");
}
