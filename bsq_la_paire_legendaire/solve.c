/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 00:37:44 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/26 20:50:07 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serviette.h"

void	fill_with_42(int **map, int square, int l, int c)
{
	int		i;
	int		j;

	i = l;
	while (i < l + square)
	{
		j = c;
		while (j < c + square)
		{
			map[i][j] = 7;
			j++;
		}
		i++;
	}
}

void	memorise(int **map, int *donnees, int consigne)
{
	static int	static_square;
	static int	static_l;
	static int	static_c;

	if (consigne == 0)
	{
		if (donnees[0] > static_square)
		{
			static_square = donnees[0];
			static_l = donnees[1];
			static_c = donnees[2];
		}
	}
	else if (consigne == 1)
	{
		fill_with_42(map, static_square, static_l, static_c);
	}
	else if (consigne == 2)
	{
		static_square = 0;
		static_l = 0;
		static_c = 0;
	}
}

int		square_dim(int **map, int *donnees, int nbr_l, int nbr_c)
{
	int		square;
	int		i;
	int		j;
	int		temoin;

	temoin = 1;
	square = 0;
	while (temoin == 1)
	{
		if ((donnees[1] + square) == nbr_l || (donnees[2] + square) == nbr_c)
			break ;
		i = donnees[1] - 1;
		while (++i <= donnees[1] + square)
		{
			j = donnees[2] - 1;
			while (++j <= donnees[2] + square)
				if (map[i][j] != 0)
					temoin = 0;
		}
		square++;
	}
	if (temoin == 0)
		return (square - 1);
	else
		return (square);
}

void	solve_map(int **map, int nbr_lines, int nbr_columns)
{
	int		*donnees;

	if (!(donnees = (int *)malloc(3 * sizeof(int))))
		exit(1);
	donnees[1] = 0;
	while (donnees[1] < nbr_lines)
	{
		donnees[2] = 0;
		while (donnees[2] < nbr_columns)
		{
			donnees[0] = square_dim(map, donnees, nbr_lines, nbr_columns);
			memorise(map, donnees, 0);
			donnees[2] = donnees[2] + 1;
		}
		donnees[1] = donnees[1] + 1;
	}
	memorise(map, donnees, 1);
	memorise(map, donnees, 2);
}
