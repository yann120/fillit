/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:02:10 by fwuensch          #+#    #+#             */
/*   Updated: 2018/11/25 14:48:50 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcapitalize(char *s)
{
	int		i;

	i = 0;
	s[i] = ft_toupper(s[i]);
	while (s[++i])
	{
		s[i] = ft_tolower(s[i]);
		if (!ft_isalnum(s[i - 1]))
			s[i] = ft_toupper(s[i]);
	}
	return (s);
}
