/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 01:59:55 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/10 05:12:10 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrev(char *str)
{
	int n;
	int temp;
	int compte;
	int decompte;

	n = ft_strlen(str);
	compte = 0;
	decompte = n - 1;
	while (compte < decompte)
	{
		temp = str[decompte];
		str[decompte] = str[compte];
		str[compte] = temp;
		compte = compte + 1;
		decompte = decompte - 1;
	}
	return (str);
}
