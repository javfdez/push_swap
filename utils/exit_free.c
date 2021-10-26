/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:17:31 by javferna          #+#    #+#             */
/*   Updated: 2021/10/27 00:57:49 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	error_end(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_inputs(char **inputs)
{
	int	i;

	i = 0;
	while (inputs[i])
		free(inputs[i++]);
	free(inputs);
}

void	free_i_s_error(char **inputs, t_list **stack_a)
{
	int	i;

	i = 0;
	if (inputs)
	{
		while (inputs[i])
			free(inputs[i++]);
		free(inputs);
	}
	if (stack_a)
		ft_lstclear(*&stack_a, free);
	error_end();
}
