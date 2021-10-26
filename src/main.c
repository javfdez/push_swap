/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:57:47 by javferna          #+#    #+#             */
/*   Updated: 2021/10/26 21:38:51 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	fill_stack(char **inputs, t_list **stack_a)
{
	int		n;
	int		i;
	t_list	*aux;

	i = -1;
	n = 0;
	while (inputs[++i])
	{
		n = ft_atoi_ps(inputs[i], inputs, *(&stack_a));
		if (!*stack_a)
			*stack_a = ft_lstnew(&n);
		else
		{
			aux = ft_lstnew(&n);
			ft_lstadd_back(*(&stack_a), aux);
			free(aux);
		}
	}
}

static void	check_inputs(char **inputs, t_list **stack_a)
{
	int	i;
	int	j;

	i = 0;
	if (!inputs)
		error_end();
	while (inputs[++i])
	{
		j = 0;
		if (inputs[i][j] == '-' || inputs[i][j] == '+')
			j++;
		while (inputs[i][j])
		{
			if (inputs[i][j] < '0' || inputs[i][j++] > '9')
				free_i_s_error(inputs, *(&stack_a));
		}
	}
}

static char	*argv_whitesp(char *argv)
{
	int		i;
	char	*str;

	i = -1;
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

int	main(int argc, char const **argv)
{
	int		i;
	char	*str;
	char	**inputs;
	t_list	*stack_a;

	i = 0;
	while (++i < argc)
	{
		str = argv_whitesp(argv[i]);
		inputs = ft_split(str, ' ');
		free(str);
		check_inputs(inputs, &stack_a);
		fill_stack(inputs, &stack_a);
		free_inputs(inputs);
	}
	ft_lstclear(&stack_a, NULL);
	return (0);
}
