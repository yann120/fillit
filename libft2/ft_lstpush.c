/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:29:22 by fwuensch          #+#    #+#             */
/*   Updated: 2018/11/25 12:34:03 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstpush(t_list **list, t_list *element)
{
	t_list *curr;
	t_list *head;

	head = *list;
	curr = head;
	while (curr->next)
		curr = curr->next;
	curr->next = element;
	*list = head;
}
