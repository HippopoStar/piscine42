/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 21:02:55 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/26 21:10:26 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serviette.h"

void	liberator_enonce(char **enonce)
{
	int		i;

	i = 0;
	while (enonce[i])
	{
		free(enonce[i]);
		i++;
	}
	free(enonce);
}

void	liberator_map(int **map, int nbr_lines)
{
	int		i;

	i = 0;
	while (i < nbr_lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	liberator(char **enonce, int **map, int nbr_lines)
{
	liberator_enonce(enonce);
	liberator_map(map, nbr_lines);
}
