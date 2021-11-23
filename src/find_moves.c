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

static int	compare_counters(int a, int btop, int bbot, int *moves) //hacer esta funcion
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

static int moves_b_bot(t_stack *stack_b, int value, t_maxmin *maxmin)
{
	t_stack	*rev;
	t_stack	*aux;
	int		bbot;

	bbot = -1;
	rev = ft_lstlast_stack(stack_b);
	while (++bbot)
	{
		aux = stack_b;
		while (aux->next->content != rev->content)
			aux = aux->next;
		if (aux->content == maxmin->max)//ver si se haría con aux o con rev
		{
			if (value > maxmin->max)
				maxmin->max = value;
			if (value < maxmin->min)
				maxmin->min = value;
			if (value == maxmin->min || value == maxmin->max)
				break;
		}
		if (rev->content < value && aux->content > value)
			break;
		rev = aux;
	}
	return (bbot);
}

static int moves_b_top(t_stack *stack_b, int value, t_maxmin *maxmin)
{
	int	btop;

	btop = -1;
	while (++btop)
	{
		if (stack_b->content == maxmin->max)
		{
			if (value > maxmin->max)
				maxmin->max = value;
			if (value < maxmin->min)
				maxmin->min = value;
			if (value == maxmin->min || value == maxmin->max)
				break;
		}
		if (stack_b->content > value && stack_b->next->content < value)
			break;
		stack_b = stack_b->next;
	}
	return (bbot);
}

static int	find_moves_b(t_stack *stack_b, int value, int cnt, int *moves)
{
	static t_maxmin	maxmin;
	int		btop;
	int		bbot;

	if ((!stack_b || (stack_b->content < value
		&& ft_lstlast_stack(stack_b)->content > value)))
	{
		if (*moves == TOP)
			*moves = TOPATOPB;
		if (*moves == BOT)
			*moves = BOTATOPB;
		return(cnt);
	}
	if (!stack_b->next)
	{
		maxmin = init_maxmin(value, stack_b->content, &maxmin);
		if (*moves == TOP)
			*moves = TOPATOPB;
		if (*moves == BOT)
			*moves = BOTATOPB;
		return(cnt);
	}
	btop = moves_b_top(stack_b, value, &maxmin);
	bbot = moves_b_bot(stack_b, value, &maxmin);
	return(compare_counters()); //hacer esta funcion
} //actualizar el * con los movimientos optimos y devolver el contador
// el puntero viene con el valor correspondiente a al movimiento realizado en a

static int	stack_a_rev(t_stack *stack_a, int node, t_stack **rev)
{
	t_stack	*aux;
	int		abot;

	abot = 1;
	while (++abot && *rev->content >= node)
	{
		aux = stack_a;
		while (aux->next->content != *rev->content)
			aux = aux->next;
		*rev = aux;
	}
	return (abot);
}

int	find_moves(t_stack *stack_a, t_stack *stack_b, int node)
{
	t_stack	*rev;
	int		atop;
	int		abot;
	int 	atopb;
	int		abotb;

	atop = 0;
	atopb = TOP;
	abotb = BOT;
	rev = ft_lstlast_stack(stack_a);
	while (++atop && stack_a->content >= node)
		stack_a = stack_a->next;
	abot = stack_a_rev(stack_a, node, &rev);
	atop = find_moves_b(stack_b, stack_a->content, atop, &atopb);
	abot = find_moves_b(stack_b, rev.target->content, abot, &abotb);
	if (atop <= abot)
		return(atopb);
	return(abotb);
}
