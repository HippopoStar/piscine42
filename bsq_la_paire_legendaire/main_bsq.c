/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 19:43:35 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/26 07:20:04 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>											//Penser a retirer

void	ft_putchar(char c);
void	print_map(int **map, int nbr_lines, int nbr_columns);
void	print_enonce(char **enonce);

int		bsq_files(char *argv);

int		ft_atoi(char *str);
char	**read_enonce(int nbr_lines, int *nbr_columns, int fd);
int		**initialize_map(int nbr_lines, int nbr_columns);
void	fill_map(char **enonce, int **map, char empty, char obstacle);
void	solve_map(int **map, int nbr_lines, int nbr_columns);
void	from_map_to_perl_set(char **enonce, int **map, char fill_character);

#include <stdlib.h>
#include <unistd.h>

char	*aux_read_parameters(char *parameters_line, int	*length_parameters, int fd)
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
	while (i < *length_parameters - 1)											//test
	{
		par_temp[i] = parameters_line[i];
		i++;
	}
	free(parameters_line);
	read(fd, &par_temp[*length_parameters - 1], 1);								//test
	if (par_temp[*length_parameters - 1] == '\n')
	{
		return (par_temp);
	}
	else
	{
		return (aux_read_parameters(par_temp, length_parameters, fd));
	}
}

int		read_parameters(int *nbr_lines, char *characters, int fd)
{
	int		length_parameters;
	char	*parameters_line;

	if (!(parameters_line = (char *)malloc((1 + 1) * sizeof(char))))					//test
	{
		return (0);
	}
	parameters_line[0] = '0';
	parameters_line[1] = '\0';															//test
	length_parameters = 1;
	parameters_line = aux_read_parameters(parameters_line, &length_parameters, fd);
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
		;
	if (!(read_parameters(&nbr_lines, characters, file_descriptor)))
		;
	printf("%i\n%c\n%c\n%c\n", nbr_lines, characters[0], characters[1], characters[2]);				//Penser a retirer
//
	nbr_columns = 0;
	enonce = read_enonce(nbr_lines, &nbr_columns, file_descriptor);
	nbr_columns = nbr_columns - 1;
	printf("%i\n", nbr_columns);														//Penser a retirer
	map = initialize_map(nbr_lines, nbr_columns);
	fill_map(enonce, map, characters[0], characters[1]);
	print_enonce(enonce);
	ft_putchar('\n');
//	print_map(map, nbr_lines, nbr_columns);			//Test
//	ft_putchar('\n');
	solve_map(map, nbr_lines, nbr_columns);
//	print_map(map, nbr_lines, nbr_columns);			//Test
//	ft_putchar('\n');
	from_map_to_perl_set(enonce, map, characters[2]);
	print_enonce(enonce);
//
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
		i = 1;
		while (i < argc)
		{
			printf("%s\n", argv[i]);					//Penser a retirer
			if (bsq_files(argv[i]) == 1)
			{
				printf("TEST\n");						//Penser a retirer
				return (0);
			}
			if (i < argc - 1)
			{
				write(1, "\n", 1);
			}
			i++;
		}
	}
	return (0);
}
