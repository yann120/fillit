/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:46:11 by fwuensch          #+#    #+#             */
/*   Updated: 2018/11/18 16:40:25 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int val, size_t len)
{
	unsigned char *ptr;

	ptr = dest;
	while (len)
	{
		*ptr = val;
		ptr++;
		len--;
	}
	return (dest);
}
