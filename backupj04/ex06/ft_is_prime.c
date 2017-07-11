/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 09:30:08 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/10 09:48:08 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int n)
{
	int i;

	if (n <= 1)
	{
		return (0);
	}
	i = 2;
	while (i < n / i)
	{
		if ((n / i) * i == n)
		{
			return (0);
		}
		i++;
	}
	return (1);
}