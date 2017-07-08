/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 05:35:34 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/08 06:40:56 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);

/*
** Affichage de la derniere chaine
*/

void	aux4_ft_print_combn(int n)
{
	char a;

	a = '9' - (n - 1);
	while (a <= '9')
	{
		ft_putchar(a);
		a++;
	}
}

/*
** Affiche une chaine de n caracteres
*/

void	aux3_ft_print_combn(char *chaine, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(chaine[i]);
		i++;
	}
	ft_putchar(',');
	ft_putchar(' ');
}

/*
** Etablit la nouvelle chaine d'apres la precedente
*/

void	aux1_ft_print_combn(char *chaine, int n)
{
	int i;
	int i_bis;

	i = 0;
	while (chaine[n - 1 - i] == '9' - i && i < n)
	{
		i++;
	}
	if (i < n)
	{
		i_bis = n - 1 - i;
		chaine[i_bis] = chaine[i_bis] + 1;
		while (i_bis < (n - 1))
		{
			i_bis++;
			chaine[i_bis] = chaine[i_bis - 1] + 1;
		}
	}
}

void	aux0_ft_print_combn(char *chaine, int n)
{
	aux3_ft_print_combn(chaine, n);
	aux1_ft_print_combn(chaine, n);
	if (chaine[0] < '9' - (n - 1))
	{
		aux0_ft_print_combn(chaine, n);
	}
}

void	ft_print_combn(int n)
{
	char	*error;
	char	*chaine;
	int		i;

	chaine = (char *)malloc(n * sizeof(char));
	i = 0;
	while (i < n)
	{
		chaine[i] = i + 48;
		i++;
	}
	aux0_ft_print_combn(chaine, n);
	aux4_ft_print_combn(n);
	free(chaine);
}
