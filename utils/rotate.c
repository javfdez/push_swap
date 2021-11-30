/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:40:11 by javferna          #+#    #+#             */
/*   Updated: 2021/11/30 20:15:00 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	do_rotate(t_stack **stack)
{
	t_stack	aux;

	aux.next = *stack;
	ft_lstadd_back_stack(stack, ft_lstnew_stack((*stack)->content));
	*stack = (*stack)->next;
	free(aux.next);
}

void	rotate(t_stack **stack_a, t_stack **stack_b, int ab)
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

static void	do_r_rotate(t_stack **stack)
{
	t_stack	aux;

	aux.next = *stack;
	while (aux.next->next->next)
		aux.next = aux.next->next;
	ft_lstadd_front_stack(stack, aux.next->next);
	aux.next->next = NULL;
}

void	r_rotate(t_stack **stack_a, t_stack **stack_b, int ab)
{
	if (ab == RRA)
	{
		do_r_rotate(stack_a);
		write(1, "rra\n", 4);
	}
	if (ab == RRB)
	{
		do_r_rotate(stack_b);
		write(1, "rrb\n", 4);
	}
	if (ab == RRR)
	{
		do_r_rotate(stack_a);
		do_r_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}
