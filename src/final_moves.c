/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:53:11 by javferna          #+#    #+#             */
/*   Updated: 2021/12/03 00:22:30 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	fm_top(t_stack *stack_b, int max)
{
	int	top;

	top = 0;
	while (stack_b->content != max)
	{
		stack_b = stack_b->next;
		top++;
	}
	return (top);
}

static int	fm_bot(t_stack *stack_b, int max)
{
	t_stack	*aux;
	t_stack *rev;
	int		bot;

	bot = 1;
	rev = ft_lstlast_stack(stack_b);
	while (rev->content != max)
	{
		aux = stack_b;
		while (aux->next->content != rev->content)
			aux = aux->next;
		rev = aux;
		bot++;
	}
	return (bot);
}

void	push_back(t_stack **stack_a, t_stack **stack_b)
{
	int	top;
	int	bot;

	top = fm_top(*stack_b, maxmin_up_check(0, 0, CHECK).max);
	bot = fm_bot(*stack_b, maxmin_up_check(0, 0, CHECK).max);
	if (top <= bot)
	{
		while (top-- > 0)
			rotate(NULL, stack_b, RB);
	}
	else
	{
		while (bot-- > 0)
			r_rotate(NULL, stack_b, RRB);
	}
	while (*stack_b)
		push(stack_a, stack_b, PA);
}
