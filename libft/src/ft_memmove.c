/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:17:30 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/15 12:58:24 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char*)ft_memalloc(n + 1);
	ft_memcpy(temp, src, (n + 1));
	while (i < n)
	{
		*(char*)(dest + i) = temp[i];
		i++;
	}
	return (dest);
}
