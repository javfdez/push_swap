/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:20:04 by javferna          #+#    #+#             */
/*   Updated: 2021/11/01 12:25:15 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	check_moves(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	j;
	t_list	aux;

	if (!stack_b)
		return (0);

}

void	push_swap(t_list **stack_a)
{
	t_list	*stack_b;
	t_list	*aux;

	stack_b = NULL;
	aux->next = *stack_a;
	while (*stack_a)
	{
		if (check_moves(*stack_a, stack_b))
	}
}
