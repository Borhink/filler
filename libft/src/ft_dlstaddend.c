/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 00:44:16 by qhonore           #+#    #+#             */
/*   Updated: 2016/02/03 00:50:19 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstaddend(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*dlist;

	if (!dlst || !new)
		return ;
	dlist = *dlst;
	if (!dlist)
	{
		*dlst = new;
		return ;
	}
	while (dlist->next)
		dlist = dlist->next;
	new->back = dlist;
	dlist->next = new;
}
