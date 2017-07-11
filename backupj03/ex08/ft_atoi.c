/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:21:00 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/11 07:56:32 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	aux_ft_atoi(char *str, int *neg, int *d)
{
	*neg = 0;
	*d = 0;
	while (str[*d] == '\n' || str[*d] == '\t' || str[*d] == '\v' ||
			str[*d] == '\f' || str[*d] == '\r' || str[*d] == ' ')
	{
		*d = *d + 1;
	}
	if (str[*d] == '-')
	{
		*neg = 1;
	}
	*d = *d + *neg;
}

int		ft_atoi(char *str)
{
	int n;
	int neg;
	int p10;
	int d;
	int l;

	n = 0;
	p10 = 1;
	aux_ft_atoi(str, &neg, &d);
	l = d;
	while (str[l] >= '0' && str[l] <= '9')
		l++;
	while (--l >= d)
	{
		n = n + ((str[l] - 48) * p10);
		p10 = p10 * 10;
	}
	if (neg == 1)
		n = -n;
	if (n != 0)
		return (n);
	else
		return (0);
}
