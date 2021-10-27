/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:57:47 by javferna          #+#    #+#             */
/*   Updated: 2021/10/27 12:09:18 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
			free_inputs_stack(inputs, stack_a);
		*n = ft_atoi_ps(inputs[i], inputs, *(&stack_a));
		if (!*stack_a)
			*stack_a = ft_lstnew((void *)n);
		else
			ft_lstadd_back(*&stack_a, ft_lstnew(n));
	}
}

static void	check_inputs(char **inputs, t_list **stack_a)
{
	int	i;
	int	j;

	i = -1;
	if (!inputs || !*inputs)
		free_inputs_stack(inputs, stack_a);
	while (inputs[++i])
	{
		j = 0;
		if (inputs[i][j] == '-' || inputs[i][j] == '+')
			j++;
		while (inputs[i][j])
		{
			if (inputs[i][j] < '0' || inputs[i][j] > '9')
				free_inputs_stack(inputs, stack_a);
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
		free_inputs(inputs);
	}
	ft_lstclear(&stack_a, free);
	return (0);
}
