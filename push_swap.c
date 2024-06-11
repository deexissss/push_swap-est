/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:33:43 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/11 14:38:04 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_stack(t_stack_node **stack)
{
	t_stack_node	*current;

	current = *stack;
	ft_printf("Stack: ");
	while (current != NULL)
	{
		ft_printf("%d ", current->data);
		current = current->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack_node	**stacka;
	t_stack_node	**stackb;
	int				i;
	int				nb;
	t_stack_node	cheap;

	stacka = malloc(sizeof(t_stack_node));
	stackb = malloc(sizeof(t_stack_node));
	if (!stacka || !stackb)
		return (0);
	if (argc <= 1)
		ft_printf("\n");
	i = 1;
	if (argc > 1)
	{
		while (i + 1 <= argc)
		{
			nb = ft_atoi(argv[i]);
			add_node(stacka, nb);
			i++;
		}
		sort_three(stacka);
		ft_print_stack(stacka);
	}
	while (!is_empty(stacka))
		ft_remove(stacka);
	free(stacka);
	free(stackb);
	return (0);
}
