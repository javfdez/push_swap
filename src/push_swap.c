/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:07:53 by javferna          #+#    #+#             */
/*   Updated: 2021/12/07 20:13:16 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	do_moves(t_stack **stack_a, t_stack **stack_b, int node, int moves)
{
	int		top;
	int		bot;

	if (moves == TOP)
	{
		top = moves_top(*stack_a, node);
		while (top-- > 0)
			rotate(stack_a, NULL, RA);
		push(stack_b, stack_a, PB);
	}
	else
	{
		bot = moves_bot(*stack_a, node);
		while (bot-- > 0)
			r_rotate(stack_a, NULL, RRA);
		push(stack_b, stack_a, PB);
	}
}

static int	find_best_moves(t_stack *stack_a, int node)
{
	int		atop;
	int		abot;

	abot = moves_bot(stack_a, node);
	atop = moves_top(stack_a, node);
	if (atop <= abot)
		return (TOP);
	return (BOT);
}

static void	move_chunks(t_stack **stack_a, t_stack **stack_b, int size, int bl)
{
	int			chunk;
	int			node;
	int			cnt;
	int			moves;

	chunk = 1;
	node = 0;
	cnt = 0;
	while (chunk < (bl - 1))
	{
		node += size;
		while (cnt < node && *stack_a)
		{
			moves = find_best_moves(*stack_a, node);
			do_moves(stack_a, stack_b, node, moves);
			cnt++;
		}
		chunk++;
	}
}

static int	is_ordered(t_stack *stack_a)
{
	while (stack_a->next && stack_a->next->content - stack_a->content == 1)
		stack_a = stack_a->next;
	if (!stack_a->next)
		return (1);
	return (0);
}

void	push_swap(t_stack **stack_a)
{
	int		total_size;
	int		size;
	int		bl;
	t_stack	*stack_b;

	stack_b = NULL;
	total_size = ft_lstsize_stack(*stack_a);
	index_stack(stack_a, total_size);
	if (is_ordered(*stack_a))
		return ;
	if (total_size > 5)
	{
		bl = ((3 * total_size) + 700) / 200;
		size = total_size / bl;
		move_chunks(stack_a, &stack_b, size, bl);
		move_chunks(stack_a, &stack_b, total_size, ONECHUNK);
		push_back(stack_a, &stack_b, total_size);
	}
	else
		small_size(stack_a, &stack_b, total_size);
}
