/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pour_les_forts.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsalome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:53:58 by vsalome           #+#    #+#             */
/*   Updated: 2017/07/25 14:53:28 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	**ft_split_whitespaces(char *str);

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;

	if (argc == 2)
	{
		split = ft_split_whitespaces(argv[1]);
		i = 0;
		while (split[i])
		{
			j = 0;
			while (split[i][j])
			{
				ft_putchar(split[i][j]);
				j++;
			}
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
