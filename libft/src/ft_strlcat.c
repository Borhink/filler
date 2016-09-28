/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:21:48 by qhonore           #+#    #+#             */
/*   Updated: 2015/11/30 20:06:18 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(dst);
	if (len > size)
		return (ft_strlen(src) + size);
	while (src[i] != '\0' && (int)(size - len - 1) > 0)
	{
		dst[len + i] = src[i];
		i++;
		size--;
	}
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}
