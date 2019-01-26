/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:46:15 by fwuensch          #+#    #+#             */
/*   Updated: 2018/11/25 21:25:51 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	char	c;
	char	*end;

	end = str + ft_strlen(str) - 1;
	while (str < end)
	{
		c = *str;
		*str++ = *end;
		*end-- = c;
	}
}
