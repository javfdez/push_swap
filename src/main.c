/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:57:47 by javferna          #+#    #+#             */
/*   Updated: 2021/10/27 21:55:22 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	check_duplicates(t_list *stack_a) //Check or redo
{
	t_list	aux;
	t_list	aux2;

	aux.next = stack_a->next;
	aux2.content = stack_a->content;
	aux2.next = stack_a->next;
	while(aux.next)
	{
		while(aux2.next)
		{
			if(*(int *)aux2.content == *(int *)aux2.next->content)
				free_all_error(NULL, &stack_a);
			aux2.next = aux2.next->next;
		}
		aux2.next = aux.next->next;
		aux2.content = aux.next->content;
		aux.next= aux.next->next;
	}
}

static void	fill_stack(char **inputs, t_list **stack_a)
{
	int		*n;
	int		i;

	i = -1;
	n = NULL;
	while (inputs[++i])
	{
		n = malloc(sizeof(int) * 1);
		if (!n)
			free_all_error(inputs, stack_a);
		ft_atoi_ps(inputs[i], inputs, stack_a, n);
		if (!*stack_a)
			*stack_a = ft_lstnew((void *)n);
		else
			ft_lstadd_back(*&stack_a, ft_lstnew(n));
	}
	free_inputs(inputs);
}

static void	check_inputs(char **inputs, t_list **stack_a)
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
		while (inputs[i][j])
		{
			if (inputs[i][j] < '0' || inputs[i][j] > '9')
				free_all_error(inputs, stack_a);
			j++;
		}
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	char	**inputs;
	t_list	*stack_a;

	i = -1;
	if (argc > 1)
		i = 0;
	stack_a = NULL;
	while (++i < argc)
	{
		if (argc == 1)
			str = str_fd0(argv[0]);
		else
			str = whitespace(argv[i]);
		inputs = ft_split(str, ' ');
		if (str)
			free(str);
		check_inputs(inputs, &stack_a);
		fill_stack(inputs, &stack_a);
	}
	check_duplicates(stack_a);
	ft_printcontent(stack_a);
	ft_lstclear(&stack_a, free);
	return (0);
}
