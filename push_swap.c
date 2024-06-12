/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:33:43 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/12 14:35:34 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	**stacka;
	t_stack_node	**stackb;
	int				i;
	int				nb;

	stacka = malloc(sizeof(t_stack_node));
	stackb = malloc(sizeof(t_stack_node));
	if (!stacka || !stackb)
		return (0);
	i = 1;
	if (argc > 1)
	{
		while (i + 1 <= argc)
		{
			nb = ft_atoi(argv[i]);
			add_node(stacka, nb);
			i++;
		}
		if (ft_checksorted(*stacka) != 1)
		{
			if (stack_size(*stacka) == 2)
				sa(stacka);
			else
				sort_stack(stacka, stackb);
		}
		display_stack(*stacka);
	}
	while (!is_empty(stacka))
		ft_remove(stacka);
	free(stacka);
	free(stackb);
	ft_printf("\n");
	return (0);
}
