/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 17:20:29 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/25 17:25:24 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strdup(char *str);

int		main(int argc, char **argv)
{
	char	*dup;
	int		i;

	if (argc != 2)
	{
		return (0);
	}
	else
	{
		dup = ft_strdup(argv[1]);
		i = 0;
		while (dup[i] != '\0')
		{
			ft_putchar(dup[i]);
			i++;
		}
		ft_putchar('\n');
		return (0);
	}
}
