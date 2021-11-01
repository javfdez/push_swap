/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:58:35 by javferna          #+#    #+#             */
/*   Updated: 2021/11/01 01:40:53 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define MAX_LINE 2048
# define SA 0
# define SB 1
# define SS 2
# define RA 3
# define RB 4
# define RR 5
# define RRA 6
# define RRB 7
# define RRR 8

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

void	error_end(void);
void	free_inputs(char **inputs);
void	free_all_error(char **inputs, t_list **stack);
void	ft_atoi_ps(const char *str, char **inputs, t_list **stack_a, int *n);
char	*str_fd0(char *argv);
char	*whitespace(char *argv);
void	check_duplicates(t_list *stack_a);
void	fill_stack(char **inputs, t_list **stack_a);
void	check_inputs(char **inputs, t_list **stack_a);
void	swap(t_list **stack_a, t_list **stack_b, int ab);
void	rotate(t_list **stack_a, t_list **stack_b, int ab);
void	r_rotate(t_list **stack_a, t_list **stack_b, int ab);


#endif
