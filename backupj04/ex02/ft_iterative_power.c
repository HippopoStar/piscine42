/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 08:09:55 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/12 09:57:37 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int resultat;

	if (power < 0)
	{
		return (0);
	}
	else if (power == 0)
	{
		return (1);
	}
	i = 0;
	resultat = 1;
	while (i < power)
	{
		resultat = nb * resultat;
		i++;
	}
	return (resultat);
}
