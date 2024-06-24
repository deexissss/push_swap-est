/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:33:43 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/24 14:03:03 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	display_stack(t_stack_node *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d\n", stack -> data);
		stack = stack -> next;
	}
}*/

void	create_stack(t_stack_node **stack, char **argv, int i)
{
	int	nb;

	if (syntax_error(argv[i]))
		error(*stack);
	nb = ft_atoi(argv[i]);
	if (duplicate_nb(*stack, nb))
		error(*stack);
	add_node(stack, nb);
}

void	sorting_checker(t_stack_node **stacka, t_stack_node **stackb)
{
	if (ft_checksorted(*stacka) != 1)
	{
		if (stack_size(*stacka) == 2)
			sa(stacka);
		else
			sort_stack(stacka, stackb);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	**stacka;
	t_stack_node	**stackb;
	int				i;
	int				nb;

	stacka = malloc(sizeof(t_stack_node*));
	stackb = malloc(sizeof(t_stack_node*));
	if (!stacka || !stackb)
		return (1);
	i = 1;
	if (argc > 1)
	{
		while (i + 1 <= argc)
		{
			create_stack(stacka, argv, i);
			i++;
		}
		sorting_checker(stacka, stackb);
	}
	free_stack(*stacka);
	free_stack(*stackb);
	free(stacka);
	free(stackb);
	return (0);
}
