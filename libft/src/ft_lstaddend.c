/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:10:28 by qhonore           #+#    #+#             */
/*   Updated: 2016/02/06 01:30:53 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*list;

	if (!alst || !new)
		return (0);
	list = *alst;
	if (!list)
	{
		*alst = new;
		return (1);
	}
	while (list->next)
		list = list->next;
	list->next = new;
	return (1);
}
