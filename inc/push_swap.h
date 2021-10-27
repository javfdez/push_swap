/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:58:35 by javferna          #+#    #+#             */
/*   Updated: 2021/10/27 11:38:50 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

void	error_end(void);
void	free_inputs(char **inputs);
void	free_inputs_stack(char **inputs, t_list **stack);
int		ft_atoi_ps(const char *str, char **inputs, t_list **stack_a);
char	*str_fd0(char *argv);
char	*whitespace(char *argv);

#endif
