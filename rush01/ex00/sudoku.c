/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 20:34:37 by axbal             #+#    #+#             */
/*   Updated: 2017/07/16 12:05:09 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_sdk(int **sdk);
int		is_available(int **sudoku, int l, int c, int value);

int		sudoku(int **sdk, int y, int x, char **m)
{
	int		value;

	value = 0;
	if (m[y][x] != '.')
	{
		x < 8 ? sudoku(sdk, y, x + 1, m) : sudoku(sdk, y + 1, 0, m);
		return (0);
	}
	while (value++ < 9)
	{
		if (is_available(sdk, y, x, value) == 1)
		{
			sdk[y][x] = value;
			if (y == 8 && x == 8)
				print_sdk(sdk);
			else
				x < 8 ? sudoku(sdk, y, x + 1, m) : sudoku(sdk, y + 1, 0, m);
		}
	}
	sdk[y][x] = 0;
	return (0);
}
