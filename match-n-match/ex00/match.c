/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 14:58:22 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/16 21:46:51 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		aux_match(int k, int l, char *s1, char *s2)
{
	if (s1[k] == '\0' && s2[l] == '\0')
		return (1);
	else if (s1[k] == '\0' && s2[l] == '*')
		return (aux_match(k, l + 1, s1, s2));
	else if (s2[l] == '*')
		return (aux_match(k + 1, l, s1, s2) + aux_match(k, l + 1, s1, s2));
	else if (s1[k] == s2[l])
		return (aux_match(k + 1, l + 1, s1, s2));
	else
		return (0);
}

int		match(char *s1, char *s2)
{
	if (aux_match(0, 0, s1, s2) >= 1)
		return (1);
	else
		return (0);
}
