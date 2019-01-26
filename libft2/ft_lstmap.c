/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:57:26 by fwuensch          #+#    #+#             */
/*   Updated: 2018/11/25 20:03:53 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*curr;
	t_list		*first;

	if (!lst)
		return (NULL);
	first = f(lst);
	curr = first;
	while (lst->next)
	{
		lst = lst->next;
		curr->next = f(lst);
		if (!(curr->next))
		{
			free(curr->next);
			return (NULL);
		}
		curr = curr->next;
	}
	return (first);
}
