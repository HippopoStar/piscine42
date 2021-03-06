/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_map_to_perl_set.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 03:39:28 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/26 20:55:41 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serviette.h"

void	from_map_to_perl_set(char **enonce, int **map, char fill_character)
{
	int		i;
	int		j;

	i = 0;
	while (enonce[i])
	{
		j = 0;
		while (enonce[i][j + 1])
		{
			if (map[i][j] == 7)
			{
				enonce[i][j] = fill_character;
			}
			j++;
		}
		i++;
	}
}
