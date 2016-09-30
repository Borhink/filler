/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:30:08 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/30 13:54:50 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	find_dest_x(t_env *e)
{
	int		d1;
	int		d2;


	e->d = set_pos(e->s.x > 0 ? e->m.x - 1 : 0, e->p1.y);
	d1 = ft_abs(e->d.x - e->p1.x) + ft_abs(e->d.y - e->p1.y);
	d2 = ft_abs(e->d.x - e->p2.x) + ft_abs(e->d.y - e->p2.y);
	while (d1 - d2 > 0 && d1 - d2 < -1)
	{
		if (d1 - d2 > 0)
			e->d.y += e->s.y > 0 ? -1 : 1;
		else
			e->d.y += e->s.y > 0 ? 1 : -1;
		if (e->d.y < 0 || e->d.y >= e->m.y)
		{
			e->d.y = 0;
			e->d.x += e->s.x > 0 ? -1 : 1;
		}
		d1 = ft_abs(e->d.x - e->p1.x) + ft_abs(e->d.y - e->p1.y);
		d2 = ft_abs(e->d.x - e->p2.x) + ft_abs(e->d.y - e->p2.y);
	}
}

static void	find_dest_y(t_env *e)
{
	int		d1;
	int		d2;


	e->d = set_pos(e->p1.x, e->s.y > 0 ? e->m.y - 1 : 0);
	d1 = ft_abs(e->d.x - e->p1.x) + ft_abs(e->d.y - e->p1.y);
	d2 = ft_abs(e->d.x - e->p2.x) + ft_abs(e->d.y - e->p2.y);
	while (d1 - d2 > 0 && d1 - d2 < -1)
	{
		if (d1 - d2 > 0)
			e->d.x += e->s.x > 0 ? -1 : 1;
		else
			e->d.x += e->s.x > 0 ? 1 : -1;
		if (e->d.x < 0 || e->d.x >= e->m.x)
		{
			e->d.x = 0;
			e->d.y += e->s.y > 0 ? -1 : 1;
		}
		d1 = ft_abs(e->d.x - e->p1.x) + ft_abs(e->d.y - e->p1.y);
		d2 = ft_abs(e->d.x - e->p2.x) + ft_abs(e->d.y - e->p2.y);
	}
}

void		find_axe_x(t_env *e, char map[e->m.y][e->m.x])
{
	t_pos	p;

	e->p1 = set_pos(e->s.x > 0 ? 0 : e->m.x, e->s.y > 0 ? 0 : e->m.y);
	e->p2 = set_pos(e->s.x > 0 ? e->m.x : 0, e->s.y > 0 ? e->m.y : 0);
	p.x = e->s.x < 0 ? -1 : e->m.x;
	while (e->s.x < 0 ? ++p.x < e->m.x : --p.x >= 0)
	{
		p.y = e->s.y < 0 ? -1 : e->m.y;
		while (e->s.y < 0 ? ++p.y < e->m.y : --p.y >= 0)
		{
			if (cell_type(e, map[p.y][p.x]) == 2
			&& (e->s.y > 0 ? e->p2.y > p.y : e->p2.y < p.y))
				e->p2 = p;
			if (cell_type(e, map[p.y][p.x]) == 1
			&& (e->s.y > 0 ? p.y <= e->p2.y : p.y >= e->p2.y)
			&& (e->s.x > 0 ? e->p1.x < p.x : e->p1.x > p.x))
				e->p1 = p;
		}
	}
	find_dest_x(e);
}

void		find_axe_y(t_env *e, char map[e->m.y][e->m.x])
{
	t_pos	p;

	e->p1 = set_pos(e->s.x > 0 ? 0 : e->m.x, e->s.y > 0 ? 0 : e->m.y);
	e->p2 = set_pos(e->s.x > 0 ? e->m.x : 0, e->s.y > 0 ? e->m.y : 0);
	p.y = e->s.y < 0 ? -1 : e->m.y;
	while (e->s.y < 0 ? ++p.y < e->m.y : --p.y >= 0)
	{
		p.x = e->s.x < 0 ? -1 : e->m.x;
		while (e->s.x < 0 ? ++p.x < e->m.x : --p.x >= 0)
		{
			if (cell_type(e, map[p.y][p.x]) == 2
			&& (e->s.x > 0 ? e->p2.x > p.x : e->p2.x < p.x))
				e->p2 = p;
			if (cell_type(e, map[p.y][p.x]) == 1
			&& (e->s.x > 0 ? p.x <= e->p2.x : p.x >= e->p2.x)
			&& (e->s.y > 0 ? e->p1.y < p.y : e->p1.y > p.y))
				e->p1 = p;
		}
	}
	find_dest_y(e);
}
