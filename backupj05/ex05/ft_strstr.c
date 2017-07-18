/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 09:48:30 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/18 05:23:28 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;

	if (*str != '\0')
	{
		i = 0;
		while (to_find[i] != '\0' && to_find[i] == str[i])
			i++;
		if (to_find[i] == '\0')
			return (str);
		else
			return (ft_strstr(&str[1], &to_find[0]));
	}
	else
		return (0);
}
