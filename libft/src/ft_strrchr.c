/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:55:38 by qhonore           #+#    #+#             */
/*   Updated: 2015/11/26 18:30:26 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (c == 0)
		return ((char*)(s + ft_strlen(s)));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			tmp = (char*)(s + i);
		i++;
	}
	return (tmp);
}
