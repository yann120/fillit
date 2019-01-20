/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:36:08 by fwuensch          #+#    #+#             */
/*   Updated: 2018/11/20 16:02:28 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *source, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (*(source + i))
		{
			*(dest + i) = *(source + i);
		}
		else
		{
			while (i < len)
			{
				*(dest + i) = '\0';
				i++;
			}
		}
		i++;
	}
	return (dest);
}
