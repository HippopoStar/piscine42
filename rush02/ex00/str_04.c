/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 22:17:41 by vgauther          #+#    #+#             */
/*   Updated: 2017/07/23 23:35:15 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*printsquare_04(int n, char a, char b, char c)
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

char	**rush_04(int x, int y)
{
	char	**ligne;
	int		i;

	if (!(ligne = (char **)malloc((y + 1) * sizeof(char *))))
		return (0);
	i = 0;
	if (x > 0)
	{
		if (y > 0)
			ligne[i] = printsquare_04(x, 'A', 'B', 'C');
		if (y > 2)
			while (i++ < y - 2)
				ligne[i] = printsquare_04(x, 'B', ' ', 'B');
		if (y > 1)
			ligne[i] = printsquare_04(x, 'C', 'B', 'A');
	}
	ligne[x] = NULL;
	return (ligne);
}

char	*str_4(int l, int c)
{
	char	**ligne;
	char	*str_4;
	int		i;
	int		j;
	int		k;

	ligne = rush_04(l, c);
	if (!(str_4 = (char *)malloc(((l * (c + 1)) + 1) * sizeof(char))))
		return (0);
	k = 0;
	i = -1;
	while (ligne[++i])
	{
		j = -1;
		while (ligne[i][++j])
		{
			str_4[k] = ligne[i][j];
			k++;
		}
		str_4[k] = '\n';
		k++;
		free(ligne[i]);
	}
	free(ligne);
	return (str_4);
}
