/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:09:25 by fwuensch          #+#    #+#             */
/*   Updated: 2018/12/05 17:11:56 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *restrict dst, const char *restrict src, size_t n)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	i = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	n = (len_src < n) ? len_src : n;
	while (n--)
	{
		*(dst + len_dst + i) = *(src + i);
		i++;
	}
	*(dst + len_dst + i) = '\0';
	return (dst);
}
