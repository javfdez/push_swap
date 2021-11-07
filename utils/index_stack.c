/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:37:33 by javferna          #+#    #+#             */
/*   Updated: 2021/11/07 19:48:04 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	index_stack(t_stack **stack_a, int i)
{
	t_stack	aux;
	int		j;

	j = 0;
	while (j < i)
	{
		aux.content = (*stack_a)->content;
		aux.next = (*stack_a)->next;
	}
}
