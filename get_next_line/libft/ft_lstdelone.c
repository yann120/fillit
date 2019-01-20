/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:57:32 by fwuensch          #+#    #+#             */
/*   Updated: 2018/11/25 20:03:50 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void				ft_lstdelone(t_list **list, void (*del)(void *, size_t))
{
	del((*list)->content, (*list)->content_size);
	free(*list);
	*list = NULL;
}
