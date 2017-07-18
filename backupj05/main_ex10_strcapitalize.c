/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex10_strcapitalize.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:06:06 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/17 22:09:35 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strcapitalize(char *str);

int		main(void)
{
	char phrase[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("%s\n", phrase);
	printf("%s\n", ft_strcapitalize(phrase));
	return (0);
}
