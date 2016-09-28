/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:03:29 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/23 04:13:50 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_fd(char const *s, int fd)
{
	int		len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	write(fd, s, len);
	return (len);
}
