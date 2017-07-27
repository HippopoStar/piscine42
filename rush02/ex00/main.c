/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 22:13:58 by vgauther          #+#    #+#             */
/*   Updated: 2017/07/23 23:39:39 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "index.h"

int		valid(char *str, int rush, int l, int c)
{
	char	*resultat;
	int		i;

	if (rush == 0)
		resultat = str_0(l, c);
	else if (rush == 1)
		resultat = str_1(l, c);
	else if (rush == 2)
		resultat = str_2(l, c);
	else if (rush == 3)
		resultat = str_3(l, c);
	else
		resultat = str_4(l, c);
	while (resultat[i] == str[i] && resultat[i] && str[i])
		i++;
	if (!(str[i]) && !(resultat[i]))
		return (1);
	else
		return (0);
}

void	search(char *str, int l, int c)
{
	if (str[0] == 'o' && (valid(str, 0, l, c) == 1))
		normal(0, l, c);
	else if (str[0] == '/' && (valid(str, 1, l, c) == 1))
		normal(1, l, c);
	else if (str[0] == 'A' && str[c - 1] == 'A' && (valid(str, 2, l, c) == 1))
		normal(2, l, c);
	else if (str[c - 1] == 'C' && str[(l * c) - 1] == 'C' &&
			(valid(str, 3, l, c) == 1))
		normal(3, l, c);
	else if (str[c - 1] == 'C' && str[(l * c) - 1] == 'A' &&
			(valid(str, 4, l, c) == 1))
		normal(4, l, c);
	else
		write(1, "aucune\n", 7);
}

char	*read_entry(char *entry_temp, int occurence, int *l, int *c)
{
	char	*entry;
	int		i;

	if (!(entry = (char *)malloc((occurence + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (i < occurence)
	{
		entry[i] = entry_temp[i];
		i++;
	}
	free(entry_temp);
	if (entry[occurence - 1] == '\0')
		return (entry);
	else
	{
		read(0, &entry[occurence], 1);
		if (*l == 0 && entry[occurence] != '\n')
			*c = *c + 1;
		if (entry[occurence] == '\n')
			*l = *l + 1;
		return (read_entry(entry, occurence + 1, l, c));
	}
}

int		main(void)
{
	char	*entry;
	char	*read_temp;
	int		l;
	int		c;

	read_temp = (char *)malloc(2 * sizeof(char));
	if (read_temp == NULL)
		return (0);
	if (!(read(0, read_temp, 1)))
	{
		return (0);
	}
	if (read_temp[0] != 'o' && read_temp[0] != 'A' && read_temp[0] != '/')
	{
		write(1, "aucune\n", 7);
		return (0);
	}
	l = 0;
	c = 1;
	entry = read_entry(read_temp, 1, &l, &c);
	search(entry, l, c);
	free(entry);
	return (0);
}
