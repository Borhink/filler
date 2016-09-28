/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 07:14:51 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/23 08:42:03 by qhonore          ###   ########.fr       */
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

char		*ft_uitoa_base(unsigned int nb, int base, int upper)
{
	char	*str;
	int		len;

	len = ft_len(nb, base);
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = ft_char(nb % base, upper);
		nb /= base;
	}
	return (str);
}

char		*ft_ultoa_base(unsigned long nb, int base, int upper)
{
	char	*str;
	int		len;

	len = ft_len(nb, base);
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = ft_char(nb % base, upper);
		nb /= base;
	}
	return (str);
}

char		*ft_ulltoa_base(unsigned long long nb, int base, int upper)
{
	char	*str;
	int		len;

	len = ft_len(nb, base);
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = ft_char(nb % base, upper);
		nb /= base;
	}
	return (str);
}
