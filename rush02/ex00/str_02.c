/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 22:17:12 by vgauther          #+#    #+#             */
/*   Updated: 2017/07/23 23:34:02 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*printsquare_02(int n, char a, char b, char c)
{
	char	*colonne;
	int		i;

	if (!(colonne = (char *)malloc((n + 1) * sizeof(char))))
		return (0);
	i = 0;
	colonne[i] = a;
	if (n > 2)
		while (i++ < n - 2)
			colonne[i] = b;
	if (n > 1)
		colonne[i] = c;
	colonne[i + 1] = '\n';
	colonne[n] = '\0';
	return (colonne);
}

char	**rush_02(int x, int y)
{
	char	**ligne;
	int		i;

	if (!(ligne = (char **)malloc((y + 1) * sizeof(char *))))
		return (0);
	i = 0;
	if (x > 0)
	{
		if (y > 0)
			ligne[i] = printsquare_02(x, 'A', 'B', 'A');
		if (y > 2)
			while (i++ < y - 2)
				ligne[i] = printsquare_02(x, 'B', ' ', 'B');
		if (y > 1)
			ligne[i] = printsquare_02(x, 'C', 'B', 'C');
	}
	ligne[x] = NULL;
	return (ligne);
}

char	*str_2(int l, int c)
{
	char	**ligne;
	char	*str_2;
	int		i;
	int		j;
	int		k;

	ligne = rush_02(l, c);
	if (!(str_2 = (char *)malloc(((l * (c + 1)) + 1) * sizeof(char))))
		return (0);
	k = -1;
	i = 0;
	while (ligne[++i])
	{
		j = -1;
		while (ligne[i][++j])
		{
			str_2[k] = ligne[i][j];
			k++;
		}
		str_2[k] = '\n';
		k++;
		free(ligne[i]);
	}
	free(ligne);
	return (str_2);
}
