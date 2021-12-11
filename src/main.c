/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:57:47 by javferna          #+#    #+#             */
/*   Updated: 2021/12/11 18:09:49 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static char	*whitespace(char *argv)
{
	int		i;
	char	*str;

	i = -1;
	if (!argv || !*argv)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(argv) + 1));
	if (!str)
		return (NULL);
	while (argv[++i])
	{
		if (argv[i] == '\f' || argv[i] == '\n' || argv[i] == '\r'
			|| argv[i] == '\t' || argv[i] == '\v')
			str[i] = ' ';
		else
			str[i] = argv[i];
	}
	str[i] = '\0';
	return (str);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	char	**inputs;
	t_stack	*stack_a;

	stack_a = NULL;
	i = 0;
	if (argc == 1)
		return (0);
	while (++i < argc)
	{
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
