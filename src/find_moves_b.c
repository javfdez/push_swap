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

static int	compare_counters(int a, int btop, int bbot, int *moves)
{
	if (*moves == TOP)
	{
		if ((a + bbot) < btop)
		{
			*moves = TOPABOTB;
			return (a + bbot);
		}
		else
			*moves = TOPATOPB;
		if (a <= btop)
			return (a);
		return (btop);
	}
	if ((a + btop) < bbot)
	{
		*moves = BOTATOPB;
		return (a + btop);
	}
	else
		*moves = BOTABOTB;
	if (a <= bbot)
		return (a);
	return (bbot);
}

static int	moves_b_bot(t_stack *stack_b, int value, t_maxmin *maxmin)
{
	t_stack	*rev;
	t_stack	*aux;
	int		bbot;

	bbot = 0;
	rev = ft_lstlast_stack(stack_b);
	while (++bbot)
	{
		aux = stack_b;
		while (aux->next->content != rev->content)
			aux = aux->next;
		if (rev->content == maxmin->max)
		{
			if (value > maxmin->max)
				maxmin->max = value;
			if (value < maxmin->min)
				maxmin->min = value;
			if (value == maxmin->min || value == maxmin->max)
			{
				bbot--;
				break ;
			}
		}
		if (rev->content < value && aux->content > value)
			break ;
		rev = aux;
	}
	return (bbot);
}

int	moves_b_top(t_stack *stack_b, int value, t_maxmin *maxmin)
{
	int	btop;

	btop = 0;
	while (++btop)
	{
		if (stack_b->content == maxmin->max)
		{
			if (value > maxmin->max)
				maxmin->max = value;
			if (value < maxmin->min)
				maxmin->min = value;
			if (value == maxmin->min || value == maxmin->max)
			{
				btop--;
				break ;
			}
		}
		if (stack_b->content > value && stack_b->next->content < value)
			break ;
		stack_b = stack_b->next;
	}
	return (btop);
}

int	find_moves_b(t_stack *stack_b, int value, int cnt, int *moves)
{
	static t_maxmin	maxmin;
	int				btop;
	int				bbot;

	if (!stack_b || (stack_b->content < value
			&& ft_lstlast_stack(stack_b)->content > value))
	{
		if (*moves == TOP)
			*moves = TOPATOPB;
		if (*moves == BOT)
			*moves = BOTATOPB;
		return (cnt);
	}
	if (!stack_b->next)
	{
		init_maxmin(value, stack_b->content, &maxmin);
		if (*moves == TOP)
			*moves = TOPATOPB;
		if (*moves == BOT)
			*moves = BOTATOPB;
		return (cnt);
	}
	btop = moves_b_top(stack_b, value, &maxmin);
	bbot = moves_b_bot(stack_b, value, &maxmin);
	return (compare_counters(cnt, btop, bbot, moves));
}
