/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:50:05 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/25 16:24:10 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*aux_concat(char *concatenation, char *argv, int *taille)
{
	char	*temp;
	int		i;
	int		j;

	*taille = *taille + ft_strlen(argv) + 1;
	if (!(temp = (char *)malloc((*taille + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (concatenation[i] != '\0')
	{
		temp[i] = concatenation[i];
		i++;
	}
	j = 0;
	while (argv[j] != '\0')
	{
		temp[i + j] = argv[j];
		j++;
	}
	temp[i + j] = '\n';
	temp[i + j + 1] = '\0';
	return (temp);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		taille;
	char	*concatenation;

	if (!(concatenation = (char *)malloc(sizeof(char))))
		return (0);
	*concatenation = '\0';
	taille = 0;
	i = 1;
	while (i < argc)
	{
		concatenation = aux_concat(concatenation, argv[i], &taille);
		i++;
	}
	i = 0;
	while (concatenation[i] != '\0')
		i++;
	if (i > 0)
		concatenation[i - 1] = '\0';
	return (concatenation);
}
