/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:00:37 by javferna          #+#    #+#             */
/*   Updated: 2021/11/01 13:17:29 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_b_min(t_list *stack_b)
{
	int	min;

	min = *(int *)(stack_b->content);
	while(stack_b->next)
	{
		stack_b = stack_b->next;
		if (stack_b->content < min)
			min = *(int *)(stack_b->content);
	}
	return (min);
}

static int	ft_b_max(t_list *stack_b)
{
	int	max;

	max = *(int *)(stack_b->content);
	while(stack_b->next)
	{
		stack_b = stack_b->next;
		if (stack_b->content > max)
			max = *(int *)(stack_b->content);
	}
	return (max);
}

int	check_moves(t_list *stack_a, t_list *stack_b)
{
	int		max;
	int		min;
	t_list	aux;

	if (!stack_b)
		return (0);
	max = ft_b_max(stack_b);
	if (*(int *)(stack_a->content) > max)

	min = ft_b_min(stack_b);

}
