/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 00:56:03 by qhonore           #+#    #+#             */
/*   Updated: 2016/10/02 21:29:44 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	img_put_pixel(t_env *e, t_img *i, t_pos p, int c)
{
	int		pos;
	int		size;

	size = ((e->m.y * 10 - 1) * e->img.sl) + (e->m.x * 10 * e->img.bpp / 8);
	pos = (p.y * i->sl) + (p.x * i->bpp / 8);
	if (pos > 0 && pos + 2 < size && p.x >= 0
		&& (p.x * e->img.bpp / 8) < e->img.sl)
	{
		if (i->edn)
		{
			i->d[pos] = mlx_get_color_value(e->mlx, c / 0x10000 % 0x100);
			i->d[pos + 1] = mlx_get_color_value(e->mlx, c / 0x100 % 0x100);
			i->d[pos + 2] = mlx_get_color_value(e->mlx, c % 0x100);
		}
		else
		{
			i->d[pos] = mlx_get_color_value(e->mlx, c % 0x100);
			i->d[pos + 1] = mlx_get_color_value(e->mlx, c / 0x100 % 0x100);
			i->d[pos + 2] = mlx_get_color_value(e->mlx, c / 0x10000 % 0x100);
		}
	}
}

static void	clear_img(t_img *i, t_env *e)
{
	t_pos	p;
	int		pos;

	p.y = -1;
	while (++p.y < e->m.y * 10)
	{
		p.x = -1;
		while (++p.x < e->m.x * 10)
		{
			pos = (p.y * i->sl) + (p.x * i->bpp / 8);
			i->d[pos] = 0;
			i->d[pos + 1] = 0;
			i->d[pos + 2] = 0;
		}
	}
}

static void	add_cell(t_env *e, t_pos pos, char map[e->m.y][e->m.x])
{
	t_pos	p;
	t_pos	end;

	p = set_pos(-1 + pos.x * 10, -1 + pos.y * 10);
	end = set_pos(p.x + 10, p.y + 10);
	while (++p.y < end.y)
	{
		p.x = end.x - 10;
		while (++p.x < end.x)
		{
			if (map[pos.y][pos.x] == '.')
				img_put_pixel(e, &(e->img), p, 0x918787);
			else if (map[pos.y][pos.x] == 'X')
				img_put_pixel(e, &(e->img), p, 0x212D9A);
			else if (map[pos.y][pos.x] == 'x')
				img_put_pixel(e, &(e->img), p, 0x4554DB);
			else if (map[pos.y][pos.x] == 'O')
				img_put_pixel(e, &(e->img), p, 0x8A4B1E);
			else if (map[pos.y][pos.x] == 'o')
				img_put_pixel(e, &(e->img), p, 0xDC772F);
		}
	}
}

void		game_render(t_env *e, char map[e->m.y][e->m.x])
{
	t_pos	p;

	clear_img(&(e->img), e);
	p.y = -1;
	while (++p.y < e->m.y)
	{
		p.x = -1;
		while (++p.x < e->m.x)
		{
			add_cell(e, p, map);
		}
	}
}

int			expose_hook(void *env)
{
	t_env	*e;

	e = (t_env*)env;
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img.i, 0, 0);
	return (1);
}
