/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 20:31:02 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/26 20:43:20 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serviette.h"

char	*count_columns(char *line0, int *nbr_columns, int fd)
{
	int		i;
	char	*line0_temp;

	*nbr_columns = *nbr_columns + 1;
	if (!(line0_temp = (char *)malloc((*nbr_columns + 1) * sizeof(char))))
	{
		return (0);
	}
	i = 0;
	while (line0[i] != '\0')
	{
		line0_temp[i] = line0[i];
		i++;
	}
	free(line0);
	read(fd, &line0_temp[i], 1);
	line0_temp[i + 1] = '\0';
	if (line0_temp[i] == '\n' || line0_temp[i] == '\0')
	{
		return (line0_temp);
	}
	else
	{
		return (count_columns(line0_temp, nbr_columns, fd));
	}
}

int		fill_enonce(char **enonce, int nbr_lines, int nbr_columns, int fd)
{
	int		i;

	i = 1;
	while (i < nbr_lines)
	{
		if (!(enonce[i] = (char *)malloc((nbr_columns + 1) * sizeof(char))))
		{
			return (0);
		}
		enonce[i][nbr_columns] = '\0';
		read(fd, enonce[i], nbr_columns);
		i++;
	}
	return (1);
}

void	fill_map(char **enonce, int **map, char empty, char obstacle)
{
	int		i;
	int		j;

	i = 0;
	while (enonce[i] != NULL)
	{
		j = 0;
		while (enonce[i][j] != '\0')
		{
			if (enonce[i][j] == empty)
			{
				map[i][j] = 0;
			}
			if (enonce[i][j] == obstacle)
			{
				map[i][j] = 1;
			}
			j++;
		}
		i++;
	}
}

int		**initialize_map(int nbr_lines, int nbr_columns)
{
	int		**map;
	int		i;

	if (!(map = (int **)malloc(nbr_lines * sizeof(int *))))
	{
		return (0);
	}
	i = 0;
	while (i < nbr_lines)
	{
		if (!(map[i] = (int *)malloc(nbr_columns * sizeof(int))))
		{
			return (0);
		}
		i++;
	}
	return (map);
}

char	**read_enonce(int nbr_lines, int *nbr_columns, int fd)
{
	char	**enonce;
	char	*line0;

	if (!(line0 = (char *)malloc((0 + 1) * sizeof(char))))
	{
		return (0);
	}
	line0[0] = '\0';
	line0 = count_columns(line0, nbr_columns, fd);
	line0[*nbr_columns] = '\0';
	if (!(enonce = (char **)malloc((nbr_lines + 1) * sizeof(char *))))
	{
		return (0);
	}
	enonce[0] = line0;
	enonce[nbr_lines] = NULL;
	if (!(fill_enonce(enonce, nbr_lines, *nbr_columns, fd)))
	{
		return (0);
	}
	return (enonce);
}
