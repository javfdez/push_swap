/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:33:04 by javferna          #+#    #+#             */
/*   Updated: 2021/12/08 13:43:26 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_max_and_min(t_stack *stack_a, int b_content)
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

int	check_bot(t_stack *stack_a, int b_content)
{
	int	bot;
	t_stack *rev;
	t_stack *aux;

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
