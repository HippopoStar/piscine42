/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 00:10:29 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/08 06:43:04 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_print_alphabet(void);
void	ft_print_reverse_alphabet(void);
void	ft_print_numbers(void);
void	ft_is_negative(int n);
void	ft_print_comb(void);
void	ft_print_comb2(void);
void	ft_putnbr(int nb);
void	ft_print_combn(int n);

/*
** ft_print_combn(int n);
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	ft_print_alphabet();
	ft_putchar('\n');
	ft_print_reverse_alphabet();
	ft_putchar('\n');
	ft_print_numbers();
	ft_putchar('\n');
	ft_is_negative(atoi(argv[1]));
	ft_putchar('\n');
	ft_print_comb();
	ft_putchar('\n');
	ft_print_comb2();
	ft_putchar('\n');
	ft_putnbr(atoi(argv[2]));
	ft_putchar('\n');
	ft_print_combn(atoi(argv[3]));
	ft_putchar('\n');

/*
**	int		i;
**
**	i = 0;
**	printf("argc->%d\n", argc);
**	while (argv[i])
**	{
**		printf("argv[%d]->%s\n", i, argv[i]);
**		i++;
**	}
*/
}
