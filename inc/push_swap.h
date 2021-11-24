/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:58:35 by javferna          #+#    #+#             */
/*   Updated: 2021/11/24 14:00:31 by javferna         ###   ########.fr       */
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
# define PA 9
# define PB 10
# define TOP 11
# define BOT 12
# define TOPATOPB 13
# define TOPABOTB 14
# define BOTATOPB 15
# define BOTABOTB 16
# define ONECHUNK 2

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_stack
{
	int				content;
	int				flag;
	struct s_stack	*next;
}	t_stack;

typedef struct s_index
{
	t_stack	*target;
	t_stack	*next;
}	t_index;

typedef struct s_maxmin
{
	int	max;
	int	min;
}	t_maxmin;

void	error_end(void);
void	free_inputs(char **inputs);
void	free_all_error(char **inputs, t_stack **stack);
int		ft_atoi_ps(const char *str, char **inputs, t_stack **stack_a);
char	*str_fd0(char *argv);
char	*whitespace(char *argv);
void	check_duplicates(t_stack *stack_a);
void	fill_stack(char **inputs, t_stack **stack_a);
void	check_inputs(char **inputs, t_stack **stack_a);
void	swap(t_stack **stack_a, t_stack **stack_b, int ab);
void	rotate(t_stack **stack_a, t_stack **stack_b, int ab);
void	r_rotate(t_stack **stack_a, t_stack **stack_b, int ab);
void	push(t_stack **stack_dst, t_stack **stack_src, int ab);
void	push_swap(t_stack **stack_a);
void	index_stack(t_stack **stack_a, int i);
int		ft_lstsize_stack(t_stack *lst);
void	ft_lstadd_back_stack(t_stack **lst, t_stack *new);
void	ft_lstadd_front_stack(t_stack **lst, t_stack *new);
void	ft_lstclear_stack(t_stack **lst);
t_stack	*ft_lstlast_stack(t_stack *lst);
t_stack	*ft_lstnew_stack(int content);
int		stack_a_rev(t_stack *stack_a, int node, t_stack **rev);
int		find_moves_b(t_stack *stack_b, int value, int cnt, int *moves);

#endif
