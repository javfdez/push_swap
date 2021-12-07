/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:24:22 by javferna          #+#    #+#             */
/*   Updated: 2021/11/24 18:24:22 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	moves_top(t_stack *stack_a, int node)
{
	int	atop;

	if (!stack_a->next)
		return (0);
	atop = 0;
	while (stack_a->content >= node)
	{
		stack_a = stack_a->next;
		atop++;
	}
	return (atop);
}

int	moves_bot(t_stack *stack_a, int node)
{
	t_stack	*aux;
	t_stack	*rev;
	int		abot;

	if (!stack_a->next)
		return (0);
	rev = ft_lstlast_stack(stack_a);
	abot = 1;
	while (rev->content >= node)
	{
		aux = stack_a;
		while (aux->next->content != rev->content)
			aux = aux->next;
		rev = aux;
		abot++;
	}
	return (abot);
}
