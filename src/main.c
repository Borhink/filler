/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 06:32:25 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/28 17:25:29 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	next_line(void)
{
	char	*line;

	if (get_next_line(0, &line) > 0)
		free(line);
}

t_pos	set_pos(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

void	get_map_size(char *line, t_env *e)
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

void	get_piece_size(t_env *e)
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

int		can_place(t_env *e, char map[e->m.y][e->m.x], char piece[e->p.y][e->p.x], t_pos m)
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
				if (nb > 1 || c.y < 0 || c.x < 0
				|| c.y >= e->m.y || c.x >= e->m.x
				|| (map[c.y][c.x] != '.' && map[c.y][c.x] != e->player))
					return (0);
				else if (map[c.y][c.x] == e->player)
					nb++;
			}
		}
	}
	if (nb == 1)
	{
		char	*ret;
		ret = ft_strjoin(ft_itoa(m.y), " ");
		ret = ft_strjoin(ret, ft_itoa(m.x));
		ret = ft_strjoin(ret, "\n");
		ft_putstr(ret);
		return (1);
	}
	return (0);
}

void	play(t_env *e, char map[e->m.y][e->m.x], char piece[e->p.y][e->p.x])
{
	t_pos	p;

	p.y = -1;
	while (++p.y < e->m.y)
	{
		p.x = -1;
		while (++p.x < e->m.x)
		{
			if (can_place(e, map, piece, p))
				return ;
		}
	}
	ft_putstr("0 0\n");
}

void	make_piece(t_env *e, char map[e->m.y][e->m.x])
{
	char	piece[e->p.y][e->p.x];
	char	*line;
	int		x;
	int		y;

	y = -1;
	while (++y < e->p.y)
	{
		if (get_next_line(0, &line) > 0)
		{
			x = -1;
			while (++x < e->p.x)
				piece[y][x] = line[x];
			free(line);
		}
	}
	//GET OFFSET
	play(e, map, piece);
}

void	make_map(t_env *e)
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

int		main(void)
{
	char	*line;
	t_env	e;

	e.m = set_pos(0, 0);
	if (get_next_line(0, &line) > 0)
	{
		e.player = (line[10] == '1' ? 'O' : 'X');
		free(line);
	}
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			if (!e.m.y || !e.m.x)
				get_map_size(line, &e);
			next_line();
			make_map(&e);
		}
		free(line);
	}
	return (0);
}
