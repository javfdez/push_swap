/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:15:56 by javferna          #+#    #+#             */
/*   Updated: 2021/12/07 21:11:15 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	push_it(t_stack **stack_a, t_stack **stack_b, int max, int moves)
{
	if (moves == TOP)
	{
		while ((*stack_a)->content != max)
			rotate(stack_a, NULL, RA);
	}
	else
	{
		while ((*stack_a)->content != max)
			r_rotate(stack_a, NULL, RRA);
	}
	push(stack_b, stack_a, PB);
}

static int	find_biggest(t_stack *stack_a, int total_size)
{
	t_stack	*aux;
	t_stack	*rev;
	int	top;
	int	bot;

	top = 0;
	while (stack_a->content != total_size)
	{
		stack_a = stack_a->next;
		top++;
	}
	bot = 1;
	rev = ft_lstlast_stack(stack_a);
	while (rev->content != total_size)
	{
		aux = stack_a;
		while (aux->next->content != rev->content)
			aux = aux->next;
		rev = aux;
		bot++;
	}
	if (top <= bot)
		return (TOP);
	return (BOT);
}

static void	three_numbers(t_stack **stack_a, int first, int second, int third)
{
	if (first > second && first < third && second < third)
		swap(stack_a, NULL, SA);
	else if (first > second && first > third && second > third)
	{
		swap(stack_a, NULL, SA);
		r_rotate(stack_a, NULL, RRA);
	}
	else if (first > second && first > third && second < third)
		rotate(stack_a, NULL, RA);
	else if (first < second && first < third && second > third)
	{
		swap(stack_a, NULL, SA);
		rotate(stack_a, NULL, RA);
	}
	else if (first < second && first > third && second > third)
		r_rotate(stack_a, NULL, RRA);
	else
		return ;
}

void	small_size(t_stack **stack_a, t_stack **stack_b, int total_size)
{
	int	moves;
	int	cnt;

	cnt = total_size;
	moves = 0;
	if (total_size == 2)
		swap(stack_a, NULL, SA);
	while (cnt > 3)
	{
		moves = find_biggest(*stack_a, cnt - 1);
		push_it(stack_a, stack_b, cnt - 1, moves);
		cnt--;
	}
	three_numbers(stack_a, (*stack_a)->content, (*stack_a)->next->content,
		(*stack_a)->next->next->content);
	if (total_size > 3)
	{
		push_back(stack_a, stack_b, total_size);
		rotate(stack_a, NULL, RA);
		if (total_size == 5)
			rotate(stack_a, NULL, RA);
	}
}
