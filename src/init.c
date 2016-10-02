/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:09:10 by qhonore           #+#    #+#             */
/*   Updated: 2016/10/02 23:17:09 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	create_img(t_env *e, t_img *img)
{
	if (!(img->i = mlx_new_image(e->mlx, e->m.x * 10, e->m.y * 10)))
		return (0);
	img->d = mlx_get_data_addr(img->i, &(img->bpp), &(img->sl), &(img->edn));
	return (1);
}

int			get_map_size(char *line, t_env *e)
{
	char	*tmp;

	if (ft_strstr(line, "Plateau"))
	{
		tmp = ft_strchr(line, ' ');
		e->m.y = ft_atoi(++tmp);
		tmp = ft_strchr(tmp, ' ');
		e->m.x = ft_atoi(++tmp);
		tmp = ft_strjoin("Filler - Player ", e->player == 'X' ? "blue" : "red");
		if (!(e->win = mlx_new_window(e->mlx, e->m.x * 10,
		e->m.y * 10, tmp)) || !(create_img(e, &(e->img))))
			return (0);
		free(tmp);
		mlx_expose_hook(e->win, expose_hook, e);
		mlx_hook(e->win, DESTROYNOTIFY, NOTIFY_MASK, window_destroyed, e);
		return (1);
	}
	return (0);
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
		free(line);
	}
}

static void	make_piece(t_env *e, char map[e->m.y][e->m.x])
{
	char	piece[e->p.y][e->p.x];
	char	*line;
	int		x;
	int		y;

	y = -1;
	e->o = set_pos(1000000, 1000000);
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
					e->o.x = x;
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
	t_pos	p;

	p.y = -1;
	while (++p.y < e->m.y)
	{
		if (get_next_line(0, &line) > 0)
		{
			p.x = -1;
			while (++p.x < e->m.x)
				map[p.y][p.x] = line[p.x + 4];
			free(line);
		}
	}
	get_piece_size(e);
	make_piece(e, map);
}
