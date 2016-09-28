/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:22:07 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/23 08:43:57 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(size_t nbr)
{
	int		i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int nbr)
{
	char	*s;
	int		i;
	int		neg;
	int		div;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	div = 1;
	neg = nbr < 0 ? 1 : 0;
	nbr = nbr < 0 ? -nbr : nbr;
	i = intlen(nbr);
	s = (char*)malloc(sizeof(char) * (i + neg + 1));
	s[i + neg] = '\0';
	while (--i >= 0)
	{
		s[i + neg] = ((nbr / div) % 10) + '0';
		div *= 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}

char		*ft_ltoa(long nbr)
{
	char	*s;
	int		i;
	int		neg;
	long	div;

	if (nbr == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	div = 1;
	neg = nbr < 0 ? 1 : 0;
	nbr = nbr < 0 ? -nbr : nbr;
	i = intlen(nbr);
	s = (char*)malloc(sizeof(char) * (i + neg + 1));
	s[i + neg] = '\0';
	while (--i >= 0)
	{
		s[i + neg] = ((nbr / div) % 10) + '0';
		div *= 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}

char		*ft_lltoa(long long nbr)
{
	char		*s;
	int			i;
	int			neg;
	long long	div;

	if (nbr == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	div = 1;
	neg = nbr < 0 ? 1 : 0;
	nbr = nbr < 0 ? -nbr : nbr;
	i = intlen(nbr);
	s = (char*)malloc(sizeof(char) * (i + neg + 1));
	s[i + neg] = '\0';
	while (--i >= 0)
	{
		s[i + neg] = ((nbr / div) % 10) + '0';
		div *= 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
