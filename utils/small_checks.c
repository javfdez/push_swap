/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:33:04 by javferna          #+#    #+#             */
/*   Updated: 2021/12/08 22:03:00 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	check_max_and_min(t_stack *stack_a, int b_content)
{
	t_stack	*aux;

	aux = stack_a;
	while (aux)
	{
		if (aux->content > b_content)
			break ;
		aux = aux->next;
	}
	if (!aux)
		return (MAX);
	aux = stack_a;
	while (aux)
	{
		if (aux->content < b_content)
			break ;
		aux = aux->next;
	}
	if (!aux)
		return (MIN);
	return (b_content);
}

int	search_min(t_stack *stack_a, int b_content)
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

int	check_bot(t_stack *stack_a, int b_content)
{
	int		bot;
	t_stack	*rev;
	t_stack	*aux;

	if (stack_a->content > b_content
		&& ft_lstlast_stack(stack_a)->content < b_content)
		return (0);
	rev = ft_lstlast_stack(stack_a);
	bot = 0;
	while (++bot)
	{
		aux = stack_a;
		while (aux->next->content != rev->content)
			aux = aux->next;
		if (rev->content > b_content && aux->content < b_content)
			break ;
		rev = aux;
	}
	return (bot);
}

int	check_top(t_stack *stack_a, int b_content)
{
	int	top;

	if (stack_a->content > b_content
		&& ft_lstlast_stack(stack_a)->content < b_content)
		return (0);
	top = 0;
	while (++top)
	{
		if (stack_a->content < b_content
			&& stack_a->next->content > b_content)
			break ;
		stack_a = stack_a->next;
	}
	return (top);
}

int	where_in_a(t_stack *stack_a, int b_content)
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
