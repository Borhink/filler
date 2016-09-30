/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:18:57 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/30 19:16:30 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	print_test(t_env *e, char map[e->m.y][e->m.x], char piece[e->p.y][e->p.x])
{
	t_pos	p;

	map[e->p1.y][e->p1.x] = 'P';
	map[e->p2.y][e->p2.x] = 'E';
	map[e->d.y][e->d.x] = 'D';
	p.y = -1;
	while (++p.y < e->p.y)
	{
		p.x = -1;
		while (++p.x < e->p.x)
			if (piece[p.y][p.x] == '*')
				map[e->b.y + p.y][e->b.x + p.x] = '$';
	}
	if (e->b.y >= 0 && e->b.x >= 0)
		map[e->b.y][e->b.x] = piece[0][0] == '*' ? 'B' : 'b';
	p.y = -1;
	while (++p.y < e->m.y)
	{
		p.x = -1;
		while (++p.x < e->m.x)
			ft_putchar_fd(map[p.y][p.x], e->fd);
		ft_putchar_fd('\n', e->fd);
	}
	ft_putchar_fd('\n', e->fd);
}

static int	can_place(t_env *e, char cur, int *nb, t_pos c)
{
	if (c.y < 0 || c.x < 0 || c.y >= e->m.y || c.x >= e->m.x
	|| (cur != '.' && cur != e->player && cur != e->player + 32))
		return (0);
	else if (cur == e->player || cur == e->player + 32)
		(*nb)++;
	return (*nb > 1 ? 0 : 1);
}

static void	put_position(t_pos p)
{

	ft_putnbr(p.y);
	ft_putchar(' ');
	ft_putnbr(p.x);
	ft_putchar('\n');
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
	return (nb == 1 ? 1 : 0);
}

void		play(t_env *e, char map[e->m.y][e->m.x], char piece[e->p.y][e->p.x])
{
	t_pos	p;

	e->a = 0;
	if (!e->hd && (piece_type(e, piece) || e->vd))
		find_axe_x(e, map);
	else if (!piece_type(e, piece) && !e->vd)
		find_axe_y(e, map);
	find_piece_best(e, piece);
	p.y = e->s.y < 0 ? -1 - e->o.y : e->m.y;
	e->b = set_pos(-99999, -99999);
	while (e->s.y < 0 ? ++p.y < e->m.y : --p.y >= 0 -(e->o.y))
	{
		p.x = e->s.x < 0 ? -1 - e->o.x : e->m.x;
		while (e->s.x < 0 ? ++p.x < e->m.x : --p.x >= 0 -(e->o.x))
		{
			if (place_piece(e, map, piece, p))
			{
				if (e->vd && e->hd)
				{
					print_test(e, map, piece);
					return (put_position(p));
				}
				if (get_dist(e->d, set_pos(p.x + e->bp.x, p.y + e->bp.y)) < get_dist(e->d, set_pos(e->b.x + e->bp.x, e->b.y + e->bp.y)))
					e->b = p;
			}
		}
	}
	if (e->b.y != -99999)
	{
		if (get_dist(e->d, set_pos(e->b.x + e->bp.x, e->b.y + e->bp.y)) == 0 && e->a > 0)
			e->hd = 1;
		else if (get_dist(e->d, set_pos(e->b.x + e->bp.x, e->b.y + e->bp.y)) == 0 && e->a < 0)
			e->vd = 1;
		print_test(e, map, piece);
		return (put_position(e->b));
	}
	ft_putstr("0 0\n");
}
