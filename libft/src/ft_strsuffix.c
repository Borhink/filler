/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsuffix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:31:29 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/07 20:00:26 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strsuffix(const char *str, const char *suffix)
{
	int		i;

	if (!str)
		return (0);
	if (!suffix)
		return (1);
	i = ft_strlen(str) - ft_strlen(suffix);
	if (i < 0)
		return (0);
	while (str[i] && str[i] == *suffix++)
		i++;
	return (str[i] == '\0' ? 1 : 0);
}
