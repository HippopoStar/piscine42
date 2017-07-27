/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_available.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 13:56:05 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/16 10:52:40 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		valid_cross(int **sudoku, int l, int c, int valeur)
{
	int		i;
	int		j;
	int		occur;

	i = 0;
	j = 0;
	occur = 0;
	while (i < 9)
	{
		if (sudoku[i][c] == valeur)
			occur++;
		i++;
	}
	while (j < 9)
	{
		if (sudoku[l][j] == valeur)
			occur++;
		j++;
	}
	if (occur != 2)
		return (0);
	return (1);
}

int		is_valid(int **sudoku, int l, int c, int valeur)
{
	int		i;
	int		j;
	int		occur;

	i = 0;
	occur = 0;
	if (valid_cross(sudoku, l, c, valeur) == 0)
		return (0);
	i = (l / 3) * 3;
	while (i < ((l / 3) * 3 + 3))
	{
		j = (c / 3) * 3;
		while (j < ((c / 3) * 3 + 3))
		{
			if (sudoku[i][j] == valeur)
				occur++;
			j++;
		}
		i++;
	}
	if (occur != 1)
		return (0);
	return (1);
}
