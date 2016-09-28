/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:41:12 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/07 15:42:04 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strprefix(const char *str, const char *prefix)
{
	if (!str)
		return (0);
	if (!prefix)
		return (1);
	while (*str && *prefix && *str == *prefix)
	{
		str++;
		prefix++;
	}
	return (!(*prefix));
}
