/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:07:53 by javferna          #+#    #+#             */
/*   Updated: 2021/11/22 21:46:09 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	find_best(t_stack **stack_a, t_stack **stack_b, int node)
{
	int moves;

	moves = find_moves(*stack_a, *stack_b, node, BOT); //deberia de devolver algo para saber como es mas optimo si top a top b, top a bot b...
	if (top >= bot)
	{

	}
	else
	{

	}

}

static void	first_chunks(t_stack **stack_a, t_stack **stack_b, int i, int j)
{
	int	chunk;
	int	node;
	int	cnt;

	chunk = -1;
	node = 0;
	cnt = 0;
	while (++chunk < (j - 1))
	{
		node += i;
		while (cnt++ < node)
		{
			find_best(stack_a, stack_b, node);
		}
	} //faltaria el ultimo nodo acordarse de marcar el menor y el mayor siempre en b
}

void	push_swap(t_stack **stack_a)
{
	int		i;
	int		j;
	t_stack *stack_b;

	i = ft_lstsize_stack(*stack_a);
	index_stack(stack_a, i);
	j = (3 * i + 700) / 200;
	i /= j;
	first_chunks(stack_a, &stack_b, i, j);
	last_chunk();

}
