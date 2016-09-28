/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 07:14:51 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/23 08:45:04 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(size_t nb, int base)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		len++;
	}
	return (len);
}

static char	ft_char(int nb, int upper)
{
	if (nb < 10)
		return (nb + '0');
	return (upper ? nb + 'A' - 10 : nb + 'a' - 10);
}

char		*ft_itoa_base(int value, int base, int upper)
{
	long	nb;
	int		neg;
	char	*str;
	int		len;

	nb = value;
	neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		if (base == 10)
			neg = 1;
	}
	len = ft_len(nb, base) + neg;
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = ft_char(nb % base, upper);
		nb /= base;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

char		*ft_ltoa_base(long nb, int base, int upper)
{
	int		neg;
	char	*str;
	int		len;

	neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		if (base == 10)
			neg = 1;
	}
	len = ft_len(nb, base) + neg;
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = ft_char(nb % base, upper);
		nb /= base;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

char		*ft_lltoa_base(long long nb, int base, int upper)
{
	int		neg;
	char	*str;
	int		len;

	neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		if (base == 10)
			neg = 1;
	}
	len = ft_len(nb, base) + neg;
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = ft_char(nb % base, upper);
		nb /= base;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
