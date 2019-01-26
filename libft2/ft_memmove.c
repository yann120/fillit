/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:46:35 by fwuensch          #+#    #+#             */
/*   Updated: 2018/11/19 22:18:23 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *source, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	i = 0;
	s = (char *)source;
	d = (char *)dest;
	if (s < d)
	{
		while (len)
		{
			len--;
			*(d + len) = *(s + len);
		}
	}
	else
	{
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	return (dest);
}
