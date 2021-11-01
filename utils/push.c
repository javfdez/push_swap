/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:03:01 by javferna          #+#    #+#             */
/*   Updated: 2021/11/01 10:19:01 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push(t_list **stack_dst, t_list **stack_src, int ab)
{
	t_list	*aux;

	aux->next = *stack_src;
	if (!*stack_dst)
		*stack_dst = ft_lstnew((*stack_src)->content);
	else
		ft_lstadd_front(stack_dst, ft_lstnew((*stack_src)->content));
	*stack_src = (*stack_src)->next;
	ft_lstdelone(aux->next, NULL);
	if (ab == PA)
		write(1, "pa\n", 3);
	if (ab == PB)
		write(1, "pb\n", 3);
}
