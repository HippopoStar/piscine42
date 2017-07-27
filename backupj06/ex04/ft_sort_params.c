/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 04:31:09 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/24 17:58:23 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_params(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_params(int argc, char **argv, int temoin)
{
	int		i;
	char	*p;

	if (temoin == 0)
		;
	else
	{
		temoin = 0;
		i = 1;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				p = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = p;
				temoin = 1;
			}
			i++;
		}
		ft_sort_params(argc, argv, temoin);
	}
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		return (0);
	}
	else
	{
		ft_sort_params(argc, argv, 1);
		ft_print_params(argc, argv);
		return (0);
	}
}
