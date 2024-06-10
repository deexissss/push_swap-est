/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg.lu>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:17:24 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/10 22:18:48 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack_node *stack)
{
	t_stack_node	*nb1;
	t_stack_node	*nb2;

	if (stack -> top == NULL || stack -> top -> next == NULL)
		return ;
	nb1 = stack -> top;
	nb2 = stack -> top -> next;
	nb1 -> next = nb2 -> next;
	nb2 -> next = nb1;
	stack -> top = nb2;
}

void	sa(t_stack_node *stack)
{
	ft_swap(stack);
	ft_printf("sa\n");
}

void	sb(t_stack_node *stack)
{
	ft_swap(stack);
	ft_printf("sb\n");
}

void	ss(t_stack_node *stacka, t_stack_node *stackb)
{
	ft_swap(stacka);
	ft_swap(stackb);
	ft_printf("ss\n");
}
