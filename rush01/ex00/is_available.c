/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_available.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 13:56:05 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/16 10:23:52 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_available(int **sudoku, int l, int c, int valeur)
{
	int i;
	int j;

	i = 0;
	while (i < 9 && sudoku[i][c] != valeur)
		i++;
	j = 0;
	while (j < 9 && sudoku[l][j] != valeur)
		j++;
	if (i != 9 || j != 9)
		return (0);
	i = (l / 3) * 3;
	while (i < ((l / 3) * 3 + 3))
	{
		j = (c / 3) * 3;
		while (j < ((c / 3) * 3 + 3))
		{
			if (sudoku[i][j] == valeur)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
