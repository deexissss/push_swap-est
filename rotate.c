/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg.lu>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:19:24 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/11 11:24:10 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*top_nb;
	t_stack_node	*bottom_nb;

	if (*stack == NULL || (*stack)-> next == NULL)
		return ;
	top_nb = *stack;
	bottom_nb = *stack;
	while (bottom_nb -> next != NULL)
		bottom_nb = bottom_nb -> next;
	*stack = top_nb -> next;
	(*stack)-> prev = NULL;
	top_nb -> next = NULL;
	top_nb -> prev = bottom_nb;
	bottom_nb -> next = top_nb;
}

void	ra(t_stack_node **stack)
{
	ft_rotate(stack);
	ft_printf("ra\n");
}

void	rb(t_stack_node **stack)
{
	ft_rotate(stack);
	ft_printf("rb\n");
}

void	rr(t_stack_node **stacka, t_stack_node **stackb)
{
	ft_rotate(stacka);
	ft_rotate(stackb);
	ft_printf("rr\n");
}
