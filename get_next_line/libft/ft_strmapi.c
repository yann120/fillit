/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:19:44 by fwuensch          #+#    #+#             */
/*   Updated: 2018/11/25 20:13:13 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	if (!s || !f)
		return (NULL);
	res = ft_strnew(ft_strlen(s));
	if (!res)
		return (NULL);
	ft_strcpy(res, s);
	i = -1;
	while (*(res + ++i))
		*(res + i) = f(i, *(res + i));
	return (res);
}
