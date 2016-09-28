/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:13:20 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/13 21:34:09 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;
	int		last;

	i = 0;
	j = 0;
	last = 0;
	if (!s2[0])
		return ((char*)s1);
	while (s1[i] != '\0' && i < n)
	{
		if (s2[j] == s1[i])
		{
			if (s2[j + 1] == '\0')
				return ((char*)(s1 + i - j));
			j++;
		}
		else
		{
			i = last++;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
