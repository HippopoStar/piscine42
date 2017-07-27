/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 22:26:19 by edinguim          #+#    #+#             */
/*   Updated: 2017/07/23 17:09:49 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

void	printsquare(int n, char a, char b, char c)
{
	int i;

	i = 0;
	ft_putchar(a);
	if (n > 2)
		while (i++ < n - 2)
			ft_putchar(b);
	if (n > 1)
		ft_putchar(c);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int i;

	i = 0;
	if (x > 0)
	{
		if (y > 0)
			printsquare(x, '/', '*', '\\');
		if (y > 2)
			while (i++ < y - 2)
				printsquare(x, '*', ' ', '*');
		if (y > 1)
			printsquare(x, '\\', '*', '/');
	}
}

int		main(int argc, char **argv)
{
	int a;
	int b;

	if (argc == 3)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[2]);
		rush(a, b);
	}
	return (0);
}
