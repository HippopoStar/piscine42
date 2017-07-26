/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serviette.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsalome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 21:14:09 by vsalome           #+#    #+#             */
/*   Updated: 2017/07/26 22:06:33 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVIETTE_H
# define SERVIETTE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_atoi(char *str);

void	bsq_standard(int files_descriptor);
int		read_parameters(int *nbr_lines, char *characters, int fd);
char	*aux_read_par(char *parameters_line, int *lenght_parameters, int fd);

int		bsq_files(char *argv);

char	**read_enonce(int nbr_lines, int *nbr_columns, int fd);
int		**initialize_map(int nbr_lines, int nbr_columns);
void	fill_map(char **enonce, int **map, char empty, char obstable);
int		fill_enonce(char **enonce, int nbr_lines, int nbr_columns, int fd);
char	*count_columns(char *line0, int *nbr_columns, int fd);

void	solve_map(int **map, int nbr_lines, int nbr_columns);
int		square_dim(int **map, int *donnees, int nbr_l, int nbr_c);
void	memorise(int **map, int *donnees, int consigne);
void	fill_with_42(int **map, int square, int l, int c);

void	from_map_to_perl_set(char **enonce, int **map, char fill_character);

void	print_map(int **map, int nbr_lines, int nbr_columns);
void	print_enonce(char **enonce);

void	liberator(char **enonce, int **map, int nbr_lines);
void	liberator_map(int **map, int nbr_lines);
void	libreator_enonce(char **enonce);

int		check_error(char **enonce, char *characters, int nbr_l, int nbr_c);
int		check_parameters(char *characters, int nbr_l, int nbr_c);
int		check_lines(char **enonce, int nbr_l);
int		check_enonce(char **enonce, char *characters, int nbr_l, int nbr_c);

#endif
