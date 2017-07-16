/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_match-n-match.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 21:39:16 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/16 21:41:11 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		match(char *s1, char *s2);
int		nmatch(char *s1, char *s2);

int		main(void)
{
	printf("%i\n", match("abcbd", "*b*"));
	printf("%i\n", match("abc", "a**"));
	printf("\n");
	printf("%i\n", nmatch("abcbd", "*b*"));
	printf("%i\n", nmatch("abc", "a**"));
	return (0);
}
