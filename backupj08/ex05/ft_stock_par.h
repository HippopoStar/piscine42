/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 09:14:00 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/27 10:21:25 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H

# include <stdlib.h>

typedef struct		s_stock_par
{
	int		size_param;
	char	*str;
	char	*copy;
	char	**tab;
}					t_stock_par;

int					ft_strlen(char *str);
char				*ft_strdup(char *src);

char				**ft_split_whitespaces(char *str);
void				ft_show_tab(struct s_stock_par *par);

struct s_stock_par	*ft_param_to_tab(int ac, char **av);

#endif
