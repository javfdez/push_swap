/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_fd0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:23:46 by javferna          #+#    #+#             */
/*   Updated: 2021/10/27 00:29:42 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	*whitespace(char *argv)
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

char	*str_fd0(char *argv)
{
	char	str[2000];
	char	*strw;
	char	c;
	int		i;

	if (!argv)
		return (NULL);
	i = 0;
	while(read(0, &c, 1) && i < 1999)
		str[i++] = c;
	if (i == 1999)
		error_end();
	str[i] = '\0';
	strw = whitespace(str);
	return (strw);
}
