/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 11:57:43 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/12 12:58:47 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_atoi(char *str);

int		main(void)
{
	char str[100];
/*	char lettre;
	int i;

	lettre = 'a';
	i = 0;
	while (i < 3)
	{
		str[i] = lettre;
		write(1, &str[i], 1);
		lettre++;
		i++;
	}
	printf("\n");
*/
	printf("Donner la chaine de caracteres a tester\n");
	scanf("%s", str);
	printf("%i\n", atoi(str));
	printf("%i\n", ft_atoi(str));
	return (0);
}
