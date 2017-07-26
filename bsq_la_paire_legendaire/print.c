/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 03:22:01 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/26 04:20:09 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_enonce(char **enonce)
{
	int		i;
	int		j;

	i = 0;
	while (enonce[i] != NULL)
	{
		j = 0;
		while (enonce[i][j] != '\0' && enonce[i][j] != '\n')
		{
			ft_putchar(enonce[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_map(int **map, int nbr_lines, int nbr_columns)
{
	int		i;
	int		j;

	i = 0;
	while (i < nbr_lines)
	{
		j = 0;
		while (j < nbr_columns)
		{
			ft_putchar((char)map[i][j] + '0');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
