/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:07:36 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/13 16:14:57 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (c == 0)
		return ((char*)(s + ft_strlen(s)));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		i++;
	}
	return (NULL);
}
