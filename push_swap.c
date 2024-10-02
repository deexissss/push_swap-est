/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:33:43 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/28 12:00:26 by tjehaes          ###   ########.fr       */
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

long	ft_atol(const char *nptr)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * nb);
}

void	create_stack(t_stack_node **stacka, char **argv, int i)
{
	long	nb;

	if (syntax_error(argv[i]))
		error(*stacka);
	nb = ft_atol(argv[i]);
	if (nb > INT_MAX || nb < INT_MIN)
		error(*stacka);
	if (duplicate_nb(*stacka, (int)nb))
		error(*stacka);
	add_node(stacka, (int)nb);
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

	stacka = malloc(sizeof(t_stack_node *));
	if (!stacka)
		return (1);
	*stacka = NULL;
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
			create_stack(stacka, argv, i++);
		stackb = malloc(sizeof(t_stack_node *));
		if (!stackb)
			return (1);
		*stackb = NULL;
		sorting_checker(stacka, stackb);
		free_stack(*stackb);
		free(stackb);
	}
	free_stack(*stacka);
	free(stacka);
	return (0);
}
