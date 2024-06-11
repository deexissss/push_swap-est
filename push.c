/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg.lu>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:14:26 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/11 11:12:25 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack_node **stack1, t_stack_node **stack2)
{
	int	data;

	data = ft_remove(stack1);
	if (data != -1)
		add_node(stack2, data);
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
