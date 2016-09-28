/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:38:10 by qhonore           #+#    #+#             */
/*   Updated: 2015/11/26 18:36:50 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*tmp;
	const unsigned char	*tmp2;

	i = 0;
	tmp = s1;
	tmp2 = s2;
	while (i < n)
	{
		if (tmp[i] != tmp2[i])
			return (tmp[i] - tmp2[i]);
		i++;
	}
	return (0);
}
