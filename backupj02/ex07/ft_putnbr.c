/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 04:26:09 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/08 02:39:23 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* Affichage de la derniere chaine */
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

/* Affiche une chaine de n caracteres */
void	aux3_ft_print_combn(char *A, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(A[i]);
		i++;
	}
	ft_putchar(',');
	ft_putchar(' ');
}

/* Incremente le rang i et initialise les termes suivants */
void	aux2_ft_print_combn(char *A, int i, int n)
{
	A[i] = A[i] + 1;
	while (i < (n - 1))
	{
		i++;
		A[i] = A[i - 1] + 1;
	}
}

/* Etablit la nouvelle chaine d'apres la precedente */
void	aux1_ft_print_combn(char *A, int n)
{
	int i;

	i = 0;
	while (A[n - 1 - i] == '9' - i && i < n)
	{
		i ++;
	}
	if (i < n)
	{
		aux2_ft_print_combn(A, n - 1 - i, n);
	}
}

void	aux0_ft_print_combn(char *A, int n)
{
	aux3_ft_print_combn(A, n);
	aux1_ft_print_combn(A, n);
	if (A[0] < '9' - (n - 1))
	{
		aux0_ft_print_combn(A, n);
	}
}

void	ft_print_combn(int n)
{
	char *Error;
	char *A = (char *) malloc (n * sizeof(char));
	int i;

	Error = "Erreur d'alloc'";
	i = 0;
	if (A == NULL)
	{
		while (i < 15)
		{
			ft_putchar(Error[i]);
			exit(1);
		}
	}
	i = 0;
	while (i < n)
	{
		A[i] = i + 48;
		i++;
		ft_putchar(A[i]);
	}
	aux0_ft_print_combn(A, n);
	aux4_ft_print_combn(n);
	free(A);
}

int		main(int argc, char **argv)
{
	ft_print_combn(atoi(argv[1]));
}
