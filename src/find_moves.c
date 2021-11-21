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

static int	find_moves_b(t_stack *stack_b, int value, int cnt, int i)
{

}

int	find_moves(t_stack *stack_a, t_stack *stack_b, int node, int i)
{
	t_index	rev;
	t_stack	*aux;
	int		cnt_at;
	int		cnt_ab;

	cnt_at = 0;
	cnt_ab = 1;
	rev.target = ft_lstlast_stack(stack_a);
	while (i == TOP && ++cnt_at <= i && stack_a->content >= node)
		stack_a = stack_a->next;
	while (i == BOT && ++cnt_ab <= i && rev.target->content >= node)
	{
		aux = stack_a;
		while (aux->next->content != rev.target->content)
			aux = aux->next;
		rev.target = aux->next;
	}
	if (i == TOP)
		return (find_moves_b(stack_b, stack_a->content, cnt_at, TOP)); //tener en cuenta que si a es 0 el numero es negativo!!
	return (find_moves_b(stack_b, stack_a->content, cnt_ab, BOT)); //tener en cuenta que si a es 0 el numero es negativo!!
}
