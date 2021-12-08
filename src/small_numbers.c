/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:15:56 by javferna          #+#    #+#             */
/*   Updated: 2021/12/08 21:58:43 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	end_move(t_stack **stack_a, t_stack **stack_b, int moves, int cnt)
{
	if (moves == MAX || moves == MIN)
	{
		if (ft_lstsize_stack(*stack_a) > 3)
			cnt = search_min(*stack_a, (*stack_b)->content);
		if (cnt == 3)
			r_rotate(stack_a, NULL, RRA);
		while (cnt < 3 && cnt-- > 0)
			rotate(stack_a, NULL, RA);
		cnt = 0;
	}
	else if (moves == TOP)
		cnt = check_top(*stack_a, (*stack_b)->content);
	else
		cnt = check_bot(*stack_a, (*stack_b)->content);
	while (cnt-- > 0)
	{
		if (moves == TOP)
			rotate(stack_a, NULL, RA);
		if (moves == BOT)
			r_rotate(stack_a, NULL, RRA);
	}
	push(stack_a, stack_b, PA);
}

static void	small_moves(t_stack **stack_a, t_stack **stack_b, int total_size)
{
	int	moves;
	int	cnt;

	moves = 0;
	cnt = total_size;
	while (cnt-- > 3)
	{
		moves = where_in_a(*stack_a, (*stack_b)->content);
		end_move(stack_a, stack_b, moves, 0);
	}
	cnt = search_min(*stack_a, MIN);
	while (cnt < 3 && cnt-- > 0)
		rotate(stack_a, NULL, RA);
	if (total_size == 5)
	{
		while (cnt > 2 && cnt++ < 5)
			r_rotate(stack_a, NULL, RRA);
	}
	if (total_size == 4)
	{
		while (cnt > 2 && cnt++ < 4)
			r_rotate(stack_a, NULL, RRA);
	}
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
	int	cnt;

	cnt = total_size;
	if (total_size == 2)
	{
		swap(stack_a, NULL, SA);
		return ;
	}
	while (cnt-- > 3)
		push(stack_b, stack_a, PB);
	three_numbers(stack_a, (*stack_a)->content, (*stack_a)->next->content,
		(*stack_a)->next->next->content);
	if (total_size > 3)
		small_moves(stack_a, stack_b, total_size);
}
