/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:30:08 by qhonore           #+#    #+#             */
/*   Updated: 2016/03/11 22:25:27 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_abs(int nb)
{
	return (nb < 0 ? -nb : nb);
}

double	ft_dabs(double nb)
{
	return (nb < 0 ? -nb : nb);
}

float	ft_fabs(float nb)
{
	return (nb < 0 ? -nb : nb);
}

long	ft_labs(long nb)
{
	return (nb < 0 ? -nb : nb);
}
