/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:41:43 by qhonore           #+#    #+#             */
/*   Updated: 2015/11/30 13:55:03 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (!n)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i + 1 < n)
		i++;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}
