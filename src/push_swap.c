/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:07:53 by javferna          #+#    #+#             */
/*   Updated: 2021/11/13 18:51:51 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	find_moves_b(t_stack *stack_b, int node)
{

}

static int	find_moves(t_stack *stack_a, t_stack *stack_b, int node, int bt)
{
	int	cnt_a;
	int	cnt_b;

	cnt_a = -1;
	while (bt == TOP && ++cnt_a < node)
	{
		if (stack_a->content < node)
			break ;
		stack_a = stack_a->next;
	}
	while (bt == BOT && ++cnt_a < node) //recorrer lista al revés
	{
		if (stack_a->content < node)
			break ;
		stack_a = stack_a->next;
	}
	cnt_b = find_moves_b(); //tener en cuenta que si a es 0 el numero es negativo!!
	return (cnt_a - cnt_b + 1);
}

static void	find_best(t_stack **stack_a, t_stack **stack_b, int node)
{
	int	top;
	int bot;

	top = find_moves(*stack_a, *stack_b, node, TOP);
	bot = find_moves(*stack_a, *stack_b, node, BOT);
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
	node = i;
	cnt = 0;
	while (++chunk < (j - 1))
	{
		while (cnt++ < node)
		{
			find_best(stack_a, stack_b, node);
		}
		node += i;
	}
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
