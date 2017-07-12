/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 10:43:46 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/12 10:42:20 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime_bis(int nb)
{
	int i;
	int a;

	i = 2;
	a = nb / 2;
	while (i <= a)
	{
		if (a * i == nb)
		{
			return (0);
		}
		i++;
		a = nb / i;
	}
	return (1);
}

void	aux_ft_find_next_prime(int *nb)
{
	if (ft_is_prime_bis(*nb) == 0)
	{
		*nb = *nb + 1;
		aux_ft_find_next_prime(nb);
	}
	else
	{
	}
}

int		ft_find_next_prime(int nb)
{
	if (nb <= 2)
	{
		return (2);
	}
	aux_ft_find_next_prime(&nb);
	return (nb);
}
