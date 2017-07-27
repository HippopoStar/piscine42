/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdk_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 03:10:36 by axbal             #+#    #+#             */
/*   Updated: 2017/07/16 14:01:55 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	sdk_free(int **sdk)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		free(sdk[i]);
		i++;
	}
	free(sdk);
}

int		**sdk_fill(int **sdk, char **mask)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			if (mask[i][j] == '.')
				sdk[i][j] = 0;
			else
				sdk[i][j] = (mask[i][j] - 48);
			j++;
		}
		j = 0;
		i++;
	}
	return (sdk);
}

int		**sdk_init(char **mask)
{
	int		i;
	int		**sdk;

	i = 0;
	if (!(sdk = malloc(sizeof(int *) * 9)))
		return (0);
	while (i < 9)
	{
		if (!(sdk[i] = malloc(sizeof(int) * 9)))
			return (0);
		i++;
	}
	return (sdk_fill(sdk, mask));
}
