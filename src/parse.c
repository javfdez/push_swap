/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:22:55 by javferna          #+#    #+#             */
/*   Updated: 2021/12/09 20:14:36 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	check_duplicates(t_stack *stack_a)
{
	t_stack	aux;
	t_stack	aux2;

	aux.next = stack_a->next;
	aux2.content = stack_a->content;
	aux2.next = stack_a->next;
	while (aux.next)
	{
		while (aux2.next)
		{
			if (aux2.content == aux2.next->content)
				free_all_error(NULL, &stack_a);
			aux2.next = aux2.next->next;
		}
		aux2.next = aux.next->next;
		aux2.content = aux.next->content;
		aux.next = aux.next->next;
	}
}

void	fill_stack(char **inputs, t_stack **stack_a)
{
	int		n;
	int		i;

	i = -1;
	while (inputs[++i])
	{
		n = ft_atoi_ps(inputs[i], inputs, stack_a);
		if (!*stack_a)
			*stack_a = ft_lstnew_stack(n);
		else
			ft_lstadd_back_stack(*&stack_a, ft_lstnew_stack(n));
	}
	free_inputs(inputs);
}

void	check_inputs(char **inputs, t_stack **stack_a)
{
	int	i;
	int	j;

	i = -1;
	if (!inputs || !*inputs)
		free_all_error(inputs, stack_a);
	while (inputs[++i])
	{
		j = 0;
		if (inputs[i][j] == '-' || inputs[i][j] == '+')
			j++;
		if (j == 1 && !inputs[i][j])
			free_all_error(inputs, stack_a);
		while (inputs[i][j])
		{
			if (inputs[i][j] < '0' || inputs[i][j] > '9')
				free_all_error(inputs, stack_a);
			j++;
		}
	}
}
