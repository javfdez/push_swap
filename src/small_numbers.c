/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:15:56 by javferna          #+#    #+#             */
/*   Updated: 2021/12/08 13:35:43 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	where_in_a(t_stack *stack_a, int b_content)
{
	int	extreme;
	int	top;
	int	bot;

	extreme = check_max_and_min(stack_a, b_content);
	if (extreme == b_content)
	{
		top = check_top(stack_a, b_content);
		bot = check_bot(stack_a, b_content);
		if (top <= bot)
			return (TOP);
		return (BOT);
	}
	else if (extreme == MAX)
		return (MAX);
	return (MIN);
}

static int	search_min(t_stack *stack_a, int b_content)
{
	t_stack	*aux;
	int		cnt;
	int		min;

	cnt = 0;
	min = 0;
	if (b_content == 0)
		min = 1;
	aux = stack_a;
	while (aux->content != min)
	{
		aux = aux->next;
		cnt++;
	}
	return (cnt);
}

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
	int	moves;

	moves = 0;
	cnt = total_size;
	if (total_size == 2)
		swap(stack_a, NULL, SA);
	while (cnt > 3)
	{
		push(stack_b, stack_a, PB);
		cnt--;
	}
	three_numbers(stack_a, (*stack_a)->content, (*stack_a)->next->content,
		(*stack_a)->next->next->content);
	while (total_size > 3)
	{
		moves = where_in_a(*stack_a, (*stack_b)->content);
		end_move(stack_a, stack_b, moves, 0);
		total_size--;
	}
	cnt = search_min(*stack_a, MIN);
	while (cnt < 3 && cnt-- > 0)
		rotate(stack_a, NULL, RA);
	while (cnt-- > 2)
		r_rotate(stack_a, NULL, RRA);
}
