/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:09:10 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/29 13:00:03 by qhonore          ###   ########.fr       */
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

void		make_map(t_env *e)
{
	char	map[e->m.y][e->m.x];
	char	*line;
	int		x;
	int		y;

	y = -1;
	while (++y < e->m.y)
	{
		if (get_next_line(0, &line) > 0)
		{
			x = -1;
			while (++x < e->m.x)
				map[y][x] = line[x + 4];
			free(line);
		}
	}
	get_piece_size(e);
	make_piece(e, map);
}
