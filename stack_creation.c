/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:35:24 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/11 14:21:16 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_str_to_long(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i] - '0');
	return (result * sign);
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack -> cheapest)
			return (stack);
		stack = stack -> next;
	}
	return (NULL);
}

void	sort_preparation(t_stack_node **stack, t_stack_node *top_node,
		char c_stack)
{
	while (*stack != top_node)
	{
		if (c_stack == 'a')
		{
			if (top_node -> sup_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (c_stack == 'b')
		{
			if (top_node -> sup_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	stack1_creation(t_stack_node **stack, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			error(*stack);
		n = ft_str_to_long(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error(*stack);
		if (duplicate_nb(*stack, (int)n))
			error(*stack);
		add_node(stack, (int)n);
		i++;
	}
}
