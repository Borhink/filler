/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:22:07 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/26 02:37:17 by qhonore          ###   ########.fr       */
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

char		*ft_sctoa(signed char nbr)
{
	char			*s;
	int				i;
	int				neg;
	signed char		div;

	if (nbr == -128)
		return (ft_strdup("-128"));
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

char		*ft_sitoa(short int nbr)
{
	char			*s;
	int				i;
	int				neg;
	short int		div;

	if (nbr == -32768)
		return (ft_strdup("-32768"));
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

char		*ft_imtoa(intmax_t nbr)
{
	char		*s;
	int			i;
	int			neg;
	intmax_t	div;

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

char		*ft_stoa(size_t nbr)
{
	char	*s;
	int		i;
	size_t	div;

	if (nbr == (size_t)(-9223372036854775807 - 1))
		return (ft_strdup("-9223372036854775808"));
	div = 1;
	i = intlen(nbr);
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	while (--i >= 0)
	{
		s[i] = ((nbr / div) % 10) + '0';
		div *= 10;
	}
	return (s);
}
