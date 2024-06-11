/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg.lu>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:25:26 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/11 14:16:01 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **stack)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = (*stack)-> data;
	nb2 = (*stack)-> next -> data;
	nb3 = (*stack)-> next -> next -> data;
	if (is_empty(stack) || stack_size(*stack) != 3)
		return ;
	if (nb1 > nb2 && nb2 < nb3 && nb1 > nb3)
		ra(stack);
	else if (nb1 > nb2 && nb2 > nb3 && nb1 > nb3)
	{
		sa(stack);
		rra(stack);
	}
	else if (nb1 < nb2 && nb2 > nb3 && nb1 > nb3)
		rra(stack);
	else if (nb1 > nb2 && nb2 < nb3 && nb1 < nb3)
		sa(stack);
	else if (nb1 < nb2 && nb2 > nb3 && nb1 < nb3)
	{
		sa(stack);
		ra(stack);
	}
}
