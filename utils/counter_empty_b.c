/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_empty_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:29:02 by javferna          #+#    #+#             */
/*   Updated: 2021/11/29 20:08:58 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_maxmin maxmin_update_check(int value, int content, int cu)
{
	static t_maxmin	maxmin;

	if (cu == CHECK)
		return (maxmin);
	if (cu == CREATE)
	{
		if (value > content)
		{
			maxmin.max = value;
			maxmin.min = content;
		}
		else
		{
			maxmin.max = content;
			maxmin.min = value;
		}
		return (maxmin);
	}
	if (value > maxmin.max)
		maxmin.max = value;
	else
		maxmin.min = value;
	return (maxmin);
}

int	counter_empty_b(t_stack *stack_b, int value)
{
	if (!stack_b || (stack_b->content < value
			&& ft_lstlast_stack(stack_b)->content > value))
		return (0);
	if (!stack_b->next)
	{
		maxmin_update_check(value, stack_b->content, CREATE);
		return (0);
	}
	return (1);
}
