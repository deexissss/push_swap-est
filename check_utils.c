/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg.lu>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:31:05 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/12 11:21:32 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checksorted(t_stack_node *stack)
{
	while (stack -> next != NULL)
	{
		if (stack -> data > stack -> next -> data)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

int	syntax_error(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || str[i] >= '0' && str[i] <= '9'))
		return (1);
	if ((str[i] == '+' || str[i] == '-')
		&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	duplicate_nb(t_stack_node *stack, int nb)
{
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		if (stack -> data == nb)
			return (1);
		stack = stack -> next;
	}
	return (0);
}

void	free_stack(t_stack_node *stack)
{
	t_stack_node	*next_node;

	if (!stack)
		return ;
	while (stack != NULL)
	{
		next_node = stack -> next;
		free(stack);
		stack = next_node;
	}
	free(stack);
}

void	error(t_stack_node *stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(1);
}
