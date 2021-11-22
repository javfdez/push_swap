/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves_fn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:06:21 by javferna          #+#    #+#             */
/*   Updated: 2021/11/21 22:06:21 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	best_moves(int cnt_at, int cnt_ab, int cnt_bt, int cnt_bb)
{

}

static void init_maxmin(int value, int content, t_maxmin *maxmin)
{
	if (value > stack_b->content)
	{
		maxmin->max = value;
		maxmin->min = stack_b->content;
	}
	else
	{
		maxmin->max = stack_b->content;
		maxmin->min = value;
	}
}

static int moves_b_bot(t_stack *stack_b, int value)
{
	t_index	rev;
	t_stack	*aux;
	int		cnt_bb;

	cnt_bb = -1;
	rev.target = ft_lstlast_stack(stack_b);
	while (++cnt_bb)
	{
		aux = stack_b;
		while (aux->next->content != rev.target->content)
			aux = aux->next;
		if (rev.target->content < value && aux->next->content > value)
			break;
		rev.target = aux->next;
	}
	return (cnt_bb);
}

static int moves_b_top(t_stack *stack_b, int value)
{
	int	cnt_bt;

	cnt_bt = -1;
	while (++cnt_bt)
	{
		if (stack_b->content > value && stack_b->next->content < value)
			break;
		stack_b = stack_b->next;
	}
	return (cnt_bb);
}

static int	find_moves_b(t_stack *stack_b, int value, int cnt, int *moves)
{
	static t_maxmin	maxmin;
	int		cnt_bt;
	int		cnt_bb;

	if (!stack_b || (stack_b->content < value
		&& ft_lstlast_stack(stack_b)->content > value))
		best_moves(cnt_at, cnt_ab, 0, 0);
	if (!stack_b->next)
	{
		maxmin = init_maxmin(value, stack_b->content, &maxmin);
		best_moves(cnt_at, cnt_ab, 0, 0);
	}
	cnt_bt = moves_b_top(stack_b, value, &maxmin);
	cnt_bb = moves_b_bot(stack_b, value, &maxmin);
} //actualizar el * con los movimientos optimos y devolver el contador
// el puntero viene con el valor correspondiente a al movimiento realizado en a

static int	stack_a_rev(t_stack *stack_a, int node, t_index *rev)
{
	t_stack	*aux;
	int		cnt_ab;

	cnt_ab = 1;
	while (++cnt_ab && rev->target->content >= node)
	{
		aux = stack_a;
		while (aux->next->content != rev->target->content)
			aux = aux->next;
		rev->target = aux->next;
	}
	return (cnt_ab);
}

int	find_moves(t_stack *stack_a, t_stack *stack_b, int node)
{
	t_index	rev;
	int		cnt_at;
	int		cnt_ab;
	int 	atopb;
	int		abotb;

	cnt_at = 0;
	atopb = TOP;
	abotb = BOT;
	rev.target = ft_lstlast_stack(stack_a);
	while (++cnt_at && stack_a->content >= node)
		stack_a = stack_a->next;
	cnt_ab = stack_a_rev(stack_a, node, &rev);
	cnt_at = find_moves_b(stack_b, stack_a->content, cnt_at, &atopb);
	cnt_ab = find_moves_b(stack_b, rev.target->content, cnt_ab, &abotb);
}
