/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:57:47 by javferna          #+#    #+#             */
/*   Updated: 2021/12/08 22:02:19 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	char	**inputs;
	t_stack	*stack_a;

	stack_a = NULL;
	i = -1;
	if (argc > 1)
		i = 0;
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
	push_swap(&stack_a);
	ft_lstclear_stack(&stack_a);
	return (0);
}
