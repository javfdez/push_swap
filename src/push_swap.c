/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:07:53 by javferna          #+#    #+#             */
/*   Updated: 2021/11/15 21:42:28 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	find_moves_b(t_stack *stack_b, int value)
{
	t_index	rev;
	t_stack	*aux;
	int		cnt_bt;
	int		cnt_bb;
	int		i;

	i = ft_lstsize_stack(stack_b);
	cnt_bt = -1;
	while (++cnt_bt <= i && value < stack_b->content)
		stack_b = stack_b->next;
	while (++cnt_ab <= i && rev.target->content >= node)
	{
		aux = stack_a;
		while (aux->next->content != rev.target->content)
			aux = aux->next;
		rev.target = aux->next;
	}
	if () //restar a cnt_a si son en la misma direccion los movimientos, sino sumar tener en cuenta si no hay stack_b
	return (cnt_bb);
}

static int	find_moves(t_stack *stack_a, t_stack *stack_b, int node, int i)
{
	t_index	rev;
	t_stack	*aux;
	int		cnt_at;
	int		cnt_ab;

	cnt_at = 0;
	cnt_ab = 1;
	rev.target = ft_lstlast_stack(stack_a);
	while (++cnt_at <= i && stack_a->content >= node)
		stack_a = stack_a->next;
	while (++cnt_ab <= i && rev.target->content >= node)
	{
		aux = stack_a;
		while (aux->next->content != rev.target->content)
			aux = aux->next;
		rev.target = aux->next;
	}
	return (find_moves_b(stack_b, stack_a->content, cnt_at, cnt_ab)); //tener en cuenta que si a es 0 el numero es negativo!!
}

static void	find_best(t_stack **stack_a, t_stack **stack_b, int node)
{
	int	top;
	int bot;

	top = find_moves(*stack_a, *stack_b, node, TOP);
	bot = find_moves(*stack_a, *stack_b, node, BOT); //deberia de devolver algo para saber como es mas optimo si top a top b, top a bot b...
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
