/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 14:58:22 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/16 21:34:33 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		aux_nmatch(int k, int l, char *s1, char *s2)
{
	if (s1[k] == '\0' && s2[l] == '\0')
		return (1);
	else if (s1[k] == '\0' && s2[l] == '*')
		return (aux_nmatch(k, l + 1, s1, s2));
	else if (s2[l] == '*')
		return (aux_nmatch(k + 1, l, s1, s2) + aux_nmatch(k, l + 1, s1, s2));
	else if (s1[k] == s2[l])
		return (aux_nmatch(k + 1, l + 1, s1, s2));
	else
		return (0);
}

int		nmatch(char *s1, char *s2)
{
	return (aux_nmatch(0, 0, s1, s2));
}
