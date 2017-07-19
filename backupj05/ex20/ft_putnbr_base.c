/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 02:46:32 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/19 03:41:38 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		is_base_valid(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] < 33 || base[i] == 127 || base[i] == '-' || base[i] == '+')
			return (0);
		j = 1;
		while (base[i + j] != '\0')
		{
			if (base[i + j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	else
		return (i);
}

void	print_nbr_base(int nbr, char *base, int length_base)
{
	if (nbr == 0);
	else
	{
		print_nbr_base(nbr / length_base, base, length_base);
		ft_putchar(base[nbr % length_base]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int length_base;

	length_base = is_base_valid(base);
	if (length_base == 0);
	else if (nbr == 0)
		ft_putchar(base[0]);
	else
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			print_nbr_base(-nbr, base, length_base);
		}
		else
			print_nbr_base(nbr, base, length_base);
	}
}
