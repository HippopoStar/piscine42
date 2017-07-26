/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:21:00 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/26 18:14:42 by vsalome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serviette.h"

int		ft_atoi(char *str)
{
	long int	nb;
	int			i;
	int			signe;

	nb = 0;
	i = 0;
	signe = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = (10 * nb) + (str[i] - '0');
		i++;
	}
	return ((int)(signe * nb));
}
