/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:24:01 by fwuensch          #+#    #+#             */
/*   Updated: 2018/11/26 18:35:57 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcasecmp(const char *s1, const char *s2)
{
	int		i;

	if (!s1 || !s2)
		return (-1000);
	i = 0;
	while (s1[i] && s2[i] && ft_tolower(s1[i]) == ft_tolower(s2[i]))
		i++;
	return (ft_tolower((unsigned char)s1[i]) -
			ft_tolower((unsigned char)s2[i]));
}
