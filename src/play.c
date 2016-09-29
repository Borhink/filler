/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:18:57 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/29 13:11:29 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	can_place(t_env *e, char cur, int *nb, t_pos c)
{
	if (c.y < 0 || c.x < 0 || c.y >= e->m.y || c.x >= e->m.x
	|| (cur != '.' && cur != e->player && cur != e->player + 32))
		return (0);
	else if (cur == e->player || cur == e->player + 32)
		(*nb)++;
	return (*nb > 1 ? 0 : 1);
}

static int	put_position(int nb, t_pos p)
{
	if (nb == 1)
	{
		ft_putnbr(p.y);
		ft_putchar(' ');
		ft_putnbr(p.x);
		ft_putchar('\n');
		return (1);
	}
	return (0);
}

static int	place_piece(t_env *e, char map[e->m.y][e->m.x], \
						char piece[e->p.y][e->p.x], t_pos m)
{
	t_pos	p;
	t_pos	c;
	int		nb;

	p.y = -1;
	nb = 0;
	while (++p.y < e->p.y)
	{
		p.x = -1;
		while (++p.x < e->p.x)
		{
			if (piece[p.y][p.x] == '*')
			{
				c = set_pos(p.x + m.x, p.y + m.y);
				if (!can_place(e, map[c.y][c.x], &nb, c))
					return (0);
			}
		}
	}
	return (put_position(nb, m));
}

void		play(t_env *e, char map[e->m.y][e->m.x], char piece[e->p.y][e->p.x])
{
	t_pos	p;

	p.y = -1 - e->o.y;
	while (++p.y < e->m.y/* - e->o.y*/)
	{
		p.x = -1 - e->o.x;
		while (++p.x < e->m.x/* - e->o.x*/)
		{
			if (place_piece(e, map, piece, p))
				return ;
		}
	}
	ft_putstr("0 0\n");
}
