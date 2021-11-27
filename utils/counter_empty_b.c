/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_empty_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:29:02 by javferna          #+#    #+#             */
/*   Updated: 2021/11/27 13:43:28 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_maxmin maxmin_up_check(int value, int content, int cu)
{
	static t_maxmin	maxmin;

	if (cu == CHECK)
		return (maxmin);
	init_maxmin (value, content, &maxmin);
	return (maxmin);
}

void	init_maxmin(int value, int content, t_maxmin *maxmin) //check on mac
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
		init_maxmin(value, stack_b->content, mm);
		return (0);
	}
	return (1);
}
