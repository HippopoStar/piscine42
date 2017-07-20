/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 21:47:53 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/20 08:52:31 by lcabanes         ###   ########.fr       */
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

void	clone_or_print(int echiquier[8][8], int clone[8][8], int consigne)
{
	int i;
	int j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (consigne == 0)
				clone[i][j] = echiquier[i][j];
			else if (echiquier[i][j] == 1 && consigne == 1)
				ft_putchar('1' + j);
			j++;
		}
		i++;
	}
	if (consigne == 1)
		ft_putchar('\n');
}

int		fill(int echiquier[8][8], int l, int c, int place)
{
	int clone[8][8];

	if (l == 8)
	{
		clone_or_print(echiquier, clone, 1);
		return (1);
	}
	else if (c < 8)
	{
		if (place == 0)
		{
			return (fill(echiquier, l, c, 1) + fill(echiquier, l, c + 1, 0));
		}
		else if (place == 1 && is_available(echiquier, l, c) == 1)
		{
			clone_or_print(echiquier, clone, 0);
			clone[l][c] = 1;
			return (fill(clone, l + 1, 0, 0));
		}
	}
	return (0);
}

void	ft_eight_queens_puzzle_2(void)
{
	int echiquier[8][8];
	int l;
	int c;
	int nombre_solutions;

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
	nombre_solutions = fill(echiquier, 0, 0, 0);
}
