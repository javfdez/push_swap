/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:03:01 by javferna          #+#    #+#             */
/*   Updated: 2021/11/07 19:28:34 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push(t_stack **stack_dst, t_stack **stack_src, int ab)
{
	t_stack	*aux;

	aux->next = *stack_src;
	if (!*stack_dst)
		*stack_dst = ft_lstnew_stack((*stack_src)->content);
	else
		ft_lstadd_front_stack(stack_dst, ft_lstnew_stack((*stack_src)->content));
	*stack_src = (*stack_src)->next;
	free(aux->next);
	if (ab == PA)
		write(1, "pa\n", 3);
	if (ab == PB)
		write(1, "pb\n", 3);
}
