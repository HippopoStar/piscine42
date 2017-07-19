/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex20_putnbr_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 03:26:22 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/19 03:32:22 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base);

int		main(void)
{
	int		nbr;
	char	base[100];

	printf("Donner la valeur de \"nbr\" :\n");
	scanf("%i", &nbr);
	printf("Donner la base :\n");
	scanf("%s", base);
	ft_putnbr_base(nbr, base);
	return (0);
}
