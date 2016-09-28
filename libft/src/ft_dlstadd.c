/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 00:39:03 by qhonore           #+#    #+#             */
/*   Updated: 2016/02/03 00:57:42 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd(t_dlist **dlst, t_dlist *new)
{
	if (!dlst || !new)
		return ;
	new->next = *dlst;
	if (*dlst)
		(*dlst)->back = new;
	*dlst = new;
}
