/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 16:00:02 by axbal             #+#    #+#             */
/*   Updated: 2017/07/16 14:00:52 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		sudoku(int **sdk, int l, int c, char **mask);
int		**sdk_init(char **mask);
int		check_arg(char **arg);
int		error_checker(int **sdk, char **mask);
void	sdk_free(int **sdk);

int		main(int argc, char **argv)
{
	char	*mask[9];
	int		**sdk;
	int		i;

	i = 0;
	if (argc != 10)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (i < 9)
	{
		mask[i] = argv[i + 1];
		i++;
	}
	if ((!(sdk = sdk_init(mask))) || (check_arg(argv) == 0)
			|| (error_checker(sdk, mask) == 0))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	sudoku(sdk, 0, 0, mask);
	sdk_free(sdk);
	return (0);
}
