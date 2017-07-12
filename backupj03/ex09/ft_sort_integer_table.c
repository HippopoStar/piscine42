/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 01:23:47 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/12 14:02:50 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int temoin;
	int temp;

	temoin = 0;
	i = 1;
	while (i < size)
	{
		if (tab[i - 1] > tab[i])
		{
			temp = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = temp;
			temoin = 1;
		}
		i++;
	}
	if (temoin != 0)
	{
		ft_sort_integer_table(tab, size);
	}
}
