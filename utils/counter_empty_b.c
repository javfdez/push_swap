/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_empty_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:29:02 by javferna          #+#    #+#             */
/*   Updated: 2021/11/24 18:08:56 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	init_maxmin(int value, int content, t_maxmin *maxmin)
{
	if (value > content)
	{
		maxmin->max = value;
		maxmin->min = content;
	}
	else
	{
		maxmin->max = content;
		maxmin->min = value;
	}
}

int	counter_empty_b(t_stack *stack_b, t_maxmin *mm, int value)
{
	if (!stack_b || (stack_b->content < value
			&& ft_lstlast_stack(stack_b)->content > value))
		return (0);
	if (!stack_b->next)
	{
		init_maxmin(value, stack_b->content, &mm);
		return (0);
	}
	return (1);
}
