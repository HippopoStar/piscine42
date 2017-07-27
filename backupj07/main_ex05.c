/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex05.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 16:33:00 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/25 16:37:13 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	**ft_split_whitespaces(char *str);
void	ft_print_words_tables(char **tab);

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		return (0);
	}
	else
	{
		ft_print_words_tables(ft_split_whitespaces(argv[1]));
		return (0);
	}
}
