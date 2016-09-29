/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:09:10 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/29 21:52:15 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_map_size(char *line, t_env *e)
{
	char	*tmp;

	if (ft_strstr(line, "Plateau"))
	{
		tmp = ft_strchr(line, ' ');
		e->m.y = ft_atoi(++tmp);
		tmp = ft_strchr(tmp, ' ');
		e->m.x = ft_atoi(++tmp);
	}
}

static void	get_piece_size(t_env *e)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) > 0)
	{
		tmp = ft_strchr(line, ' ');
		e->p.y = ft_atoi(++tmp);
		tmp = ft_strchr(tmp, ' ');
		e->p.x = ft_atoi(++tmp);
	}
}

static void	make_piece(t_env *e, char map[e->m.y][e->m.x])
{
	char	piece[e->p.y][e->p.x];
	char	*line;
	int		x;
	int		y;

	y = -1;
	e->o = set_pos(e->m.x * 2, e->m.y * 2);
	while (++y < e->p.y)
	{
		if (get_next_line(0, &line) > 0)
		{
			x = -1;
			while (++x < e->p.x)
			{
				if (line[x] == '*' && e->o.y > y)
					e->o.y = y;
				if (line[x] == '*' && e->o.x > x)
					e->o.y = x;
				piece[y][x] = line[x];
			}
			free(line);
		}
	}
	play(e, map, piece);
}

static void	set_direction(t_env *e)
{
	if (e->p1.y < e->p2.y)
		e->s.y = 1;
	else if (e->p1.y > e->p2.y)
		e->s.y = -1;
	else
		e->s.y = (e->p1.y < e->m.y / 2 ? -1 : 1);
	if (e->p1.x < e->p2.x)
		e->s.x = 1;
	else if (e->p1.x > e->p2.x)
		e->s.x = -1;
	else
		e->s.x = (e->p1.x < e->m.x / 2 ? -1 : 1);
}

void		make_map(t_env *e)
{
	char	map[e->m.y][e->m.x];
	char	*line;
	t_pos	p;

	p.y = -1;
	while (++p.y < e->m.y)
	{
		if (get_next_line(0, &line) > 0)
		{
			p.x = -1;
			while (++p.x < e->m.x)
			{
				map[p.y][p.x] = line[p.x + 4];
				if (cell_type(e, map[p.y][p.x]) == 1)
					e->p1 = p;
				if (cell_type(e, map[p.y][p.x]) == 2)
					e->p2 = p;
			}
			free(line);
		}
	}
	if (!e->s.y)
		set_direction(e);
	get_piece_size(e);
	make_piece(e, map);
}
