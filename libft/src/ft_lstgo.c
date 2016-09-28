/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:42:42 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/07 20:40:15 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstgo(t_list **alst, size_t n)
{
	size_t	i;

	i = 1;
	if (!alst || !(*alst))
		return (0);
	if (!n)
	{
		while ((*alst)->next)
		{
			*alst = (*alst)->next;
			i++;
		}
		return (i);
	}
	while ((*alst)->next && n-- > 1)
	{
		*alst = (*alst)->next;
		i++;
	}
	return (i);
}
