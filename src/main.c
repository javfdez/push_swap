/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:57:47 by javferna          #+#    #+#             */
/*   Updated: 2021/10/26 21:11:25 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_atoi_ps(const char *str, char **inputs, t_list **stack_a)
{
	unsigned long long	nb;
	int					i;
	int					sign;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		nb = nb * 10 + str[i++] - '0';
	if (nb > MAX_INT)
		free_i_s_error(inputs, *(&stack_a));
	return (nb * sign);
}

static void	fill_stack(char** inputs, t_list **stack_a)
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

int	main(int argc, char const **argv)
{
	int		i;
	char	**inputs;
	t_list	*stack_a;

	i = 0;
	while (++i < argc)
	{
		inputs = ft_split(argv[i], ' ');
		check_inputs(inputs, &stack_a);
		fill_stack(inputs, &stack_a);
		free_inputs(inputs);
	}
	ft_lstclear(&stack_a, NULL);
	return (0);
}
