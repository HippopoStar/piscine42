/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 21:29:02 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/26 22:19:49 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serviette.h"

int		check_enonce(char **enonce, char *characters, int nbr_l, int nbr_c)
{
	int		i;
	int		j;

	i = -1;
	while (++i < nbr_l)
	{
		j = -1;
		while (++j < nbr_c)
		{
			if (enonce[i][j] != characters[0] && enonce[i][j] != characters[1])
			{
				return (1);
			}
		}
	}
	return (0);
}

int		check_lines(char **enonce, int nbr_l)
{
	int		i;

	i = 0;
	while (i < nbr_l)
	{
		if (enonce[i] == NULL)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		check_parameters(char *characters, int nbr_l, int nbr_c)
{
	if (characters[0] == characters[1] ||
			characters[0] == characters[2] ||
			characters[1] == characters[2] ||
			nbr_l == 0 ||
			nbr_c == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		check_error(char **enonce, char *characters, int nbr_l, int nbr_c)
{
	if ((check_parameters(characters, nbr_l, nbr_c)) != 0)
	{
		ft_putstr("map error\n");
		return (1);
	}
	if ((check_lines(enonce, nbr_l)) != 0)
	{
		ft_putstr("map error\n");
		return (1);
	}
	if ((check_enonce(enonce, characters, nbr_l, nbr_c)) != 0)
	{
		ft_putstr("map error\n");
		return (1);
	}
	return (0);
}
