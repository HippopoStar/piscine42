/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 04:26:09 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/08 07:54:21 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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
