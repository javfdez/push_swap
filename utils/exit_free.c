/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:17:31 by javferna          #+#    #+#             */
/*   Updated: 2021/10/27 12:02:24 by javferna         ###   ########.fr       */
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

void	free_inputs_stack(char **inputs, t_list **stack)
{
	int	i;

	i = 0;
	while (inputs && inputs[i])
		free(inputs[i++]);
	free(inputs);
	if(*stack)
		ft_lstclear(stack, free);
	error_end();
}
