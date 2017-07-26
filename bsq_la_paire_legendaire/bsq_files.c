/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 04:13:12 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/26 06:56:27 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	bsq_standard(int file_descriptor);

int		bsq_files(char *argv)
{
	int		file_descriptor;

	file_descriptor = open(argv, O_RDONLY);
	if (file_descriptor == -1)
	{
		return (1);
	}
	else
	{
		bsq_standard(file_descriptor);
		if (close(file_descriptor) == -1)
		{
			return (1);
		}
	}
	return (0);
}
