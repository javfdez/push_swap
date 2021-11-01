/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:40:11 by javferna          #+#    #+#             */
/*   Updated: 2021/11/01 10:17:29 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	do_rotate(t_list **stack)
{
	t_list	*aux;

	aux->next = *stack;
	ft_lstadd_back(stack, ft_lstnew((*stack)->content));
	*stack = (*stack)->next;
	ft_lstdelone(aux->next, NULL);
}

void	rotate(t_list **stack_a, t_list **stack_b, int ab)
{
	if (ab == RA)
	{
		do_rotate(stack_a);
		write(1, "ra\n", 3);
	}
	if (ab == RB)
	{
		do_rotate(stack_b);
		write(1, "rb\n", 3);
	}
	if (ab == RR)
	{
		do_rotate(stack_a);
		do_rotate(stack_b);
		write(1, "rr\n", 3);
	}
}

static void	do_r_rotate(t_list **stack)
{
	t_list	*aux;

	aux->next = *stack;
	while (aux->next->next)
		aux = aux->next;
	ft_lstadd_front(stack, aux->next->next);
	aux->next = NULL;
}

void	r_rotate(t_list **stack_a, t_list **stack_b, int ab)
{
	if (ab == RRA)
	{
		do_r_rotate(stack_a);
		write(1, "rra\n", 3);
	}
	if (ab == RRB)
	{
		do_r_rotate(stack_b);
		write(1, "rrb\n", 3);
	}
	if (ab == RRR)
	{
		do_r_rotate(stack_a);
		do_r_rotate(stack_b);
		write(1, "rrr\n", 3);
	}
}
