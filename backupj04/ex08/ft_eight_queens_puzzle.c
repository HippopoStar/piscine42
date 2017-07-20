/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 21:47:53 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/20 06:59:17 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

/*
** Place une dame en coordonnees (l, c) et renvoie 1 si la case est disponible,
** renvoie seulement 0 sinon
*/

int		is_available(int echiquier[8][8], int l, int c)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i <= l)
	{
		j = 0;
		while (j <= c)
		{
			if (echiquier[l][j] == 1 || echiquier[i][c] == 1)
				return (0);
			j++;
		}
		i++;
	}
	k = 0;
	while (k <= l)
	{
		if ((c - k >= 0 && echiquier[l - k][c - k] == 1) ||
			(c + k < 8 && echiquier[l - k][c + k] == 1))
			return (0);
		k++;
	}
	return (1);
}

/*
**
*/

void	print_chessboard(int echiquier[8][8])
{
	int i;
	int j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			ft_putchar(echiquier[i][j] + '0');
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

/*
void	print_queens_positions(int echiquier[8][8])
{
	int i;
	int j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (echiquier[i][j] == 1)
				ft_putchar('1' + j);
			j++;
		}
		i++;
	}
	ft_putchar('\n');
}
*/

/*
**
*/

int		fill_chessboard(int echiquier[8][8], int l, int c, int place)
{
	int echiquier_bis[8][8];
	int i;
	int j;

	if (l == 8)
	{
		print_chessboard(echiquier);
		ft_putchar('\n');
		return (1);
	}
	else if (c < 8)
	{
		if (place == 0)
		{
			return (fill_chessboard(echiquier, l, c, 1) + fill_chessboard(echiquier, l, c + 1, 0));
		}
		else
		{
			if (is_available(echiquier, l, c) == 1)
			{
				i = 0;
				while (i < 8)
				{
					j = 0;
					while (j < 8)
					{
						echiquier_bis[i][j] = echiquier[i][j];
						j++;
					}
					i++;
				}
				echiquier_bis[l][c] = 1;
//				print_chessboard(echiquier_bis);
//				ft_putchar('\n');
				return (fill_chessboard(echiquier_bis, l + 1, 0, 0));
			}
			else
				return (0);
		}
		return (0);
	}
	return (0);
}

/*
**
*/

int		ft_eight_queens_puzzle(void)
{
	int echiquier[8][8];
	int l;
	int c;

	l = 0;
	while (l < 8)
	{
		c = 0;
		while (c < 8)
		{
			echiquier[l][c] = 0;
			c++;
		}
		l++;
	}
	return (fill_chessboard(echiquier, 0, 0, 0));
}
