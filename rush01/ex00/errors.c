/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 04:09:26 by axbal             #+#    #+#             */
/*   Updated: 2017/07/16 13:16:59 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid(int **sudoku, int l, int c, int valeur);
int		is_available(int **sudoku, int l, int c, int value);

int		g_global = 0;

int		mult(int **sdk, int y, int x, char **m)
{
	int		value;

	value = 0;
	if (g_global < 2)
	{
		if (m[y][x] != '.')
		{
			x < 8 ? mult(sdk, y, x + 1, m) : mult(sdk, y + 1, 0, m);
			return (0);
		}
		while (value++ < 9)
		{
			if (is_available(sdk, y, x, value) == 1)
			{
				sdk[y][x] = value;
				if (y == 8 && x == 8)
					g_global += 1;
				else
					x < 8 ? mult(sdk, y, x + 1, m) : mult(sdk, y + 1, 0, m);
			}
		}
		sdk[y][x] = 0;
	}
	return (g_global);
}

int		mult_solve(int **sdk, char **mask)
{
	int		solve;

	solve = mult(sdk, 0, 0, mask);
	if (g_global != 1)
		return (0);
	return (1);
}

int		error_checker(int **sdk, char **mask)
{
	int		i;
	int		j;
	int		var;

	i = 0;
	j = 0;
	var = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			if (mask[i][j] >= 49 && mask[i][j] <= 57)
			{
				if (is_valid(sdk, i, j, mask[i][j] - 48) == 0)
					return (0);
				var++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (var < 17)
		return (0);
	return (mult_solve(sdk, mask));
}
