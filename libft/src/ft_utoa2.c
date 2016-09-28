/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:22:07 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/23 08:40:46 by qhonore          ###   ########.fr       */
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

char		*ft_uctoa(unsigned char nbr)
{
	char				*s;
	int					i;
	unsigned char		div;

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

char		*ft_usitoa(unsigned short int nbr)
{
	char					*s;
	int						i;
	unsigned short int		div;

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

char		*ft_uimtoa(uintmax_t nbr)
{
	char		*s;
	int			i;
	uintmax_t	div;

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
