/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex03.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 16:09:34 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/25 16:13:06 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_concat_params(int argc, char **argv);

int		main(int argc, char **argv)
{
	char	*concatenation;
	int		i;

	concatenation = ft_concat_params(argc, argv);
	i = 0;
	while (concatenation[i] != '\0')
	{
		ft_putchar(concatenation[i]);
		i++;
	}
	return (0);
}
