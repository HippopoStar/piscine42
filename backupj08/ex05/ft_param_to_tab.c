/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 09:41:07 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/27 10:15:06 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char				*ft_strdup(char *src)
{
	int		length;
	char	*duplicate;
	int		i;

	length = ft_strlen(src);
	if (!(duplicate = (char *)malloc((length + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (i < length)
	{
		duplicate[i] = src[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*p;
	int				i;

	if (!(p = (t_stock_par *)malloc((ac + 1) * sizeof(t_stock_par))))
	{
		return (0);
	}
	i = 0;
	while (i < ac)
	{
		p[i].size_param = ft_strlen(av[i]);
		p[i].str = av[i];
		p[i].copy = ft_strdup(av[i]);
		p[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	(p + ac)->str = 0;
	return (p);
}
