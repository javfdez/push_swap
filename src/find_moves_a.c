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

int	moves_a_top(t_stack *stack_a, int node, int *value)
{
	int	atop;

	atop = 0;
	while (stack_a->content >= node)
	{
		stack_a = stack_a->next;
		atop++;
	}
	if (value)
		*value = stack_a->content;
	return (atop);
}

int	moves_a_bot(t_stack *stack_a, int node, t_stack **rev, int *value)
{
	t_stack	*aux;
	int		abot;

	if (!stack_a->next)
	{
		if (value)
			*value = (*rev)->content;
		return (0);
	}
	abot = 1;
	while ((*rev)->content >= node)
	{
		aux = stack_a;
		while (aux->next->content != (*rev)->content)
			aux = aux->next;
		*rev = aux;
		abot++;
	}
	if (value)
		*value = (*rev)->content;
	return (abot);
}
