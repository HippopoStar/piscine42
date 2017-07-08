/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 23:57:09 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/07 04:23:46 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	aux_ft_print_comb2(int a, int b)
{
	char a0;
	char a1;
	char b0;
	char b1;

	a0 = (a / 10) + 48;
	a1 = (a % 10) + 48;
	b0 = (b / 10) + 48;
	b1 = (b % 10) + 48;
	ft_putchar(a0);
	ft_putchar(a1);
	ft_putchar(' ');
	ft_putchar(b0);
	ft_putchar(b1);
	if (a != 99 || b != 99)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a <= 99)
	{
		b = 0;
		while (b <= 99)
		{
			aux_ft_print_comb2(a, b);
			b++;
		}
		a++;
	}
}
