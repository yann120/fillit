/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:51:10 by fwuensch          #+#    #+#             */
/*   Updated: 2018/11/25 23:48:48 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	finish;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_isstrwhitespace(s[start]))
		start++;
	finish = ft_strlen(s);
	while (ft_isstrwhitespace(s[finish - 1]))
		finish--;
	if (finish < start)
		finish = start;
	return (ft_strsub(s, start, finish - start));
}
