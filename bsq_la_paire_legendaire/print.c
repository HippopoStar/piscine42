/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 21:27:15 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/26 21:27:18 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serviette.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
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
