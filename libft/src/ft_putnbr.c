/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:39:51 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/23 04:26:42 by qhonore          ###   ########.fr       */
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

static int	neg_to_pos(int *n)
{
	if (*n < 0)
	{
		*n = -(*n);
		return (ft_putchar('-'));
	}
	return (0);
}

int			ft_putnbr(int n)
{
	int		ret;
	int		len;
	int		div;

	div = 1;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	ret = neg_to_pos(&n);
	len = intlen(n);
	while (len--)
		div *= 10;
	while (div > 0)
	{
		ft_putchar((n / div) % 10 + 48);
		div /= 10;
		ret++;
	}
	return (ret);
}
