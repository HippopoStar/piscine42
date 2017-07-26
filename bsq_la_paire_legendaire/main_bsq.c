/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 19:43:35 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/26 22:11:41 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serviette.h"

char	*aux_read_par(char *parameters_line, int *length_parameters, int fd)
{
	char	*par_temp;
	int		i;

	*length_parameters = *length_parameters + 1;
	if (!(par_temp = (char *)malloc((*length_parameters + 1) * sizeof(char))))
	{
		return (0);
	}
	par_temp[*length_parameters] = '\0';
	i = 0;
	while (i < *length_parameters - 1)
	{
		par_temp[i] = parameters_line[i];
		i++;
	}
	free(parameters_line);
	read(fd, &par_temp[*length_parameters - 1], 1);
	if (par_temp[*length_parameters - 1] == '\n')
	{
		return (par_temp);
	}
	else
	{
		return (aux_read_par(par_temp, length_parameters, fd));
	}
}

int		read_parameters(int *nbr_lines, char *characters, int fd)
{
	int		length_parameters;
	char	*parameters_line;
	int		i;

	if (!(parameters_line = (char *)malloc((3 + 1) * sizeof(char))))
	{
		return (0);
	}
	i = -1;
	while (++i < 3)
		parameters_line[i] = '0';
	parameters_line[3] = '\0';
	length_parameters = 3;
	parameters_line = aux_read_par(parameters_line, &length_parameters, fd);
	characters[2] = parameters_line[length_parameters - 2];
	characters[1] = parameters_line[length_parameters - 3];
	characters[0] = parameters_line[length_parameters - 4];
	parameters_line[length_parameters - 4] = '\0';
	*nbr_lines = ft_atoi(parameters_line);
	return (1);
}

void	bsq_standard(int file_descriptor)
{
	int		**map;
	char	**enonce;
	int		nbr_lines;
	int		nbr_columns;
	char	*characters;

	if (!(characters = (char *)malloc(3 * sizeof(char))))
		exit(1);
	if (!(read_parameters(&nbr_lines, characters, file_descriptor)))
		exit(1);
	nbr_columns = 0;
	enonce = read_enonce(nbr_lines, &nbr_columns, file_descriptor);
	nbr_columns = nbr_columns - 1;
	if ((check_error(enonce, characters, nbr_lines, nbr_columns)) == 0)
	{
		map = initialize_map(nbr_lines, nbr_columns);
		fill_map(enonce, map, characters[0], characters[1]);
		solve_map(map, nbr_lines, nbr_columns);
		from_map_to_perl_set(enonce, map, characters[2]);
		print_enonce(enonce);
		liberator(enonce, map, nbr_lines);
	}
}

int		main(int argc, char **argv)
{
	int		i;

	if (argc < 2)
	{
		bsq_standard(0);
	}
	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			if (bsq_files(argv[i]) == 1)
			{
				return (0);
			}
			if (i < argc - 1)
			{
				ft_putchar('\n');
			}
		}
	}
	return (0);
}
