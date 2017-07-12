/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex09_ft_sort_integer_table.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:12:24 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/12 14:05:39 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_integer_table(int *tab, int size);

int		main(void)
{
	int i;
	int size;
	printf("Donner la taille du tableau d'entiers\n");
	scanf("%i", &size);
	int tab[8];
	i = 0;
	while (i < size)
	{
		printf("Donner l'entier occupant la place %i du tableau\n", i);
		scanf("%i", &tab[i]);
		i++;
	}

	i = 0;
	printf("{");
	while (i < size - 1)
	{
		printf("%i, ", tab[i]);
		i++;
	}
	printf("%i}\n", tab[i]);

	ft_sort_integer_table(tab, size);

	i = 0;
	printf("{");
	while (i < size - 1)
	{
		printf("%i, ", tab[i]);
		i++;
	}
	printf("%i}\n", tab[i]);

	return (0);
}
