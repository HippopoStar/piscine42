/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:17:12 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/25 15:43:45 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		*ft_range(int min, int max);

int		main(void)
{
	int		i;
	int		*tab;
	int		min;
	int		max;

	printf("Donner la valeur de \"min\" :\n");
	scanf("%i", &min);
	printf("Donner la valeur de \"max\" :\n");
	scanf("%i", &max);
	tab = ft_range(min, max);
	i = 0;
	while (i < (max - min))
	{
		printf("%i, ", tab[i]);
		i++;
	}
	return (0);
}
