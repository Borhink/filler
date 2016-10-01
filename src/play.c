/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:18:57 by qhonore           #+#    #+#             */
/*   Updated: 2016/10/01 17:48:54 by qhonore          ###   ########.fr       */
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
				if (c.y >= e->m.y || c.x >= e->m.x
				|| !can_place(e, map[c.y][c.x], &nb, c))
					return (0);
			}
		}
	}
	return (nb == 1 ? 1 : 0);
}

static int	piece_dist(t_env *e, char piece[e->p.y][e->p.x], t_pos ep, t_pos pp)
{
	t_pos	p;
	t_pos	cur;
	int		dist;

	p.y = -1;
	dist = 0;
	while (++p.y < e->p.y)
	{
		p.x = -1;
		while (++p.x < e->p.x)
		{
			if (piece[p.y][p.x] == '*')
			{
				cur = set_pos(pp.x + p.x, pp.y + p.y);
				dist += get_dist(ep, cur);
			}
		}
	}
	return (dist);
}

static int	best_cell(t_env *e, char map[e->m.y][e->m.x], \
						char piece[e->p.y][e->p.x], t_pos pp)
{
	t_pos	p;
	int		cur;
	int		best;

	p.y = -1;
	best = 1000000000;
	while (++p.y < e->m.y)
	{
		p.x = -1;
		while (++p.x < e->m.x)
		{
			if (cell_type(e, map[p.y][p.x]) == 2)
			{
				if ((cur = piece_dist(e, piece, p, pp)) < best)
					best = cur;
			}
		}
	}
	return (best);
}

void		play(t_env *e, char map[e->m.y][e->m.x], char piece[e->p.y][e->p.x])
{
	t_pos	p;
	int		cur;
	int		best;

	e->b = set_pos(0, 0);
	best = 1000000000;
	p.y = -1 - e->o.y;
	while (++p.y < e->m.y)
	{
		p.x = -1 - e->o.x;
		while (++p.x < e->m.x)
		{
			if (place_piece(e, map, piece, p))
			{
				if ((cur = best_cell(e, map, piece, p)) < best)
				{
					best = cur;
					e->b = p;
				}
			}
		}
	}
	put_position(e->b);
}
