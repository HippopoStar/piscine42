/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:31:22 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/25 18:30:18 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		*temp;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	else
	{
		if (!(temp = (int *)malloc((max - min) * sizeof(int))))
			return (0);
		i = 0;
		while (min < max)
		{
			temp[i] = min;
			min++;
			i++;
		}
		*range = temp;
		return (i);
	}
}
