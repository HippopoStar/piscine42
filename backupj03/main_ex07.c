/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex07.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:25:49 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/10 03:24:04 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrev(char *str);

/*
** Je ne sais pas pourquoi le programme ne marche pas loraue la longueur declaree de la chaine
** de caractere en entree ne depasse pas de 1 la longueur reelle de la chaine
*/

int		main(void)
{
	char a[] = "Champomy";

	printf("%s", a);
	printf("%s", ft_strrev(a));
}
