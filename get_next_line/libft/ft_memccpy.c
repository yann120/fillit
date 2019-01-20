/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:19:59 by fwuensch          #+#    #+#             */
/*   Updated: 2018/11/19 18:26:16 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	void	*p;

	p = ft_memchr(source, c, n);
	if (p == NULL)
	{
		ft_memcpy(dest, source, n);
		return (NULL);
	}
	ft_memcpy(dest, source, p - source + 1);
	return (dest + (p - source + 1));
}
