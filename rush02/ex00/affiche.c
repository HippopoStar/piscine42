/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 17:15:49 by vgauther          #+#    #+#             */
/*   Updated: 2017/07/23 23:30:54 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "index.h"

void	except(int i, int x, int y)
{
	if (i == 10 || i == 11 || i == 12)
	{
		if (i == 10)
		{
			write(1, "[colle-02] [1] [1] || [colle-03] [1] [1]", 40);
			write(1, " || [colle-04] [1] [1]\n", 23);
		}
		if (i == 11)
		{
			write(1, "[colle-02] [1] [", 16);
			ft_putnbr(y);
			write(1, "] || [colle-04] [1] [", 21);
			ft_putnbr(y);
			write(1, "]", 5);
		}
		if (i == 12)
		{
			write(1, "[colle-03] [", 12);
			ft_putchar(x);
			write(1, "] [1] || [colle-04] [", 21);
			ft_putchar(x);
			write(1, "] [1]\n", 6);
		}
	}
}

void	normal(int i, int y, int x)
{
	if (i == 0)
		write(1, "[colle-00] [", 12);
	if (i == 1)
		write(1, "[colle-01] [", 12);
	if (i == 2)
		write(1, "[colle-02] [", 12);
	if (i == 3)
		write(1, "[colle-03] [", 12);
	if (i == 4)
		write(1, "[colle-04] [", 12);
	ft_putnbr(x);
	write(1, "] [", 3);
	ft_putnbr(y);
	write(1, "]\n", 2);
}
