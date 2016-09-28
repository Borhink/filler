/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 06:32:25 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/28 14:37:43 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	next_line(void)
{
	char	*line;

	if (get_next_line(0, &line) > 0)
		free(line);
}

void	get_map_size(char *line, t_env *e)
{
	char	*tmp;

	if (ft_strstr(line, "Plateau"))
	{
		tmp = ft_strchr(line, ' ');
		e->my = ft_atoi(++tmp);
		tmp = ft_strchr(tmp, ' ');
		e->mx = ft_atoi(++tmp);
	}
}

void	get_piece_size(t_env *e)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) > 0)
	{
		tmp = ft_strchr(line, ' ');
		e->py = ft_atoi(++tmp);
		tmp = ft_strchr(tmp, ' ');
		e->px = ft_atoi(++tmp);
	}
}

void	make_piece(t_env *e, char map[e->my][e->mx])
{
	char	piece[e->py][e->px];
	char	*line;
	int		x;
	int		y;

	y = -1;
	while (++y < e->py)
	{
		if (get_next_line(0, &line) > 0)
		{
			x = -1;
			while (++x < e->px)
				piece[y][x] = line[x];
			free(line);
		}
	}
	(void)map;
}

void	make_map(t_env *e)
{
	char	map[e->my][e->mx];
	char	*line;
	int		x;
	int		y;

	y = -1;
	while (++y < e->my)
	{
		if (get_next_line(0, &line) > 0)
		{
			x = -1;
			while (++x < e->mx)
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

	e.my = 0;
	e.mx = 0;
	if (get_next_line(0, &line) > 0)
	{
		e.player = (line[10] == '1' ? 'O' : 'X');
		free(line);
	}
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			if (!e.my || !e.mx)
				get_map_size(line, &e);
			next_line();
			make_map(&e);
		}
		free(line);
	}
	return (0);
}
