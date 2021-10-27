/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:57:47 by javferna          #+#    #+#             */
/*   Updated: 2021/10/27 22:22:39 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	ft_lstclear(&stack_a, free);
	return (0);
}
