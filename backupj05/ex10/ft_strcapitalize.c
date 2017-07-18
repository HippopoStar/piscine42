/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:49:53 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/18 05:24:26 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		aux_ft_strcapitalize(char *str)
{
	int i;

	if ('a' <= str[0] && str[0] <= 'z')
		str[0] = str[0] + ('A' - 'a');
	i = 1;
	while (('0' <= str[i] && str[i] <= '9') ||
			('A' <= str[i] && str[i] <= 'Z') ||
			('a' <= str[i] && str[i] <= 'z'))
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] = str[i] + ('a' - 'A');
		i++;
	}
	return (i);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (('0' <= str[i] && str[i] <= '9') ||
			('A' <= str[i] && str[i] <= 'Z') ||
			('a' <= str[i] && str[i] <= 'z'))
		{
			i = i + (aux_ft_strcapitalize(&str[i]));
		}
		i++;
	}
	return (str);
}
