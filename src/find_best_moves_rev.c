/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_moves_rev.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:19:13 by javferna          #+#    #+#             */
/*   Updated: 2021/11/24 12:19:13 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	stack_a_rev(t_stack *stack_a, int node, t_stack **rev)
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
