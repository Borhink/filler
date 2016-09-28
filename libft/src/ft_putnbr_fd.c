/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:06:28 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/23 04:27:25 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int		len;

	len = 0;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	neg_to_pos(int *n, int fd)
{
	if (*n < 0)
	{
		*n = -(*n);
		return (ft_putchar_fd('-', fd));
	}
	return (0);
}

int			ft_putnbr_fd(int n, int fd)
{
	int		ret;
	int		len;
	int		div;

	div = 1;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	ret = neg_to_pos(&n, fd);
	len = intlen(n);
	while (len--)
		div *= 10;
	while (div > 0)
	{
		ft_putchar_fd((n / div) % 10 + 48, fd);
		div /= 10;
		ret++;
	}
	return (ret);
}
