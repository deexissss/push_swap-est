/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg.lu>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:22:28 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/11 11:24:47 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*second_bottom_nb;
	t_stack_node	*bottom_nb;

	if (*stack == NULL || (*stack)-> next == NULL)
		return ;
	second_bottom_nb = NULL;
	bottom_nb = *stack;
	while (bottom_nb -> next != NULL)
	{
		second_bottom_nb = bottom_nb;
		bottom_nb = bottom_nb -> next;
	}
	second_bottom_nb -> next = NULL;
	bottom_nb -> next = *stack;
	bottom_nb -> prev = NULL;
	*stack = bottom_nb;
}

void	rra(t_stack_node **stack)
{
	ft_reverse_rotate(stack);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **stack)
{
	ft_reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **stacka, t_stack_node **stackb)
{
	ft_reverse_rotate(stacka);
	ft_reverse_rotate(stackb);
	ft_printf("rrr\n");
}
