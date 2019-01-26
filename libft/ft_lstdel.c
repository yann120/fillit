/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:57:31 by fwuensch          #+#    #+#             */
/*   Updated: 2018/11/25 19:20:57 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstdel(t_list **list, void (*del)(void *, size_t))
{
	if ((*list)->next)
		ft_lstdel(&(*list)->next, del);
	ft_lstdelone(&(*list), del);
}
