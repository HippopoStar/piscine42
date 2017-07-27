/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 16:23:33 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/27 17:32:23 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	aux_ft_putnbr(long int n)
{
	if (n > 0)
	{
		aux_ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
}

void	ft_putnbr(int nb)
{
	long int n;

	n = (long int)nb;
	if (n == 0)
	{
		ft_putchar('0');
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	aux_ft_putnbr(n);
}

void	ft_show_tab(struct s_stock_par *par)
{
	int		i;
	int		j;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		j = 0;
		while (par[i].tab[j])
		{
			ft_putstr(par[i].tab[j]);
			ft_putchar('\n');
			j++;
		}
		i++;
	}
}
