/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:10:34 by qhonore           #+#    #+#             */
/*   Updated: 2016/10/02 21:37:03 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	next_line(void)
{
	char	*line;

	if (get_next_line(0, &line) > 0)
		free(line);
}

int		get_dist(t_pos a, t_pos b)
{
	int		dist;

	dist = ft_abs(a.x - b.x) + ft_abs(a.y - b.y);
	return (dist);
}

t_pos	set_pos(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

int		cell_type(t_env *e, char cell)
{
	if (cell == '.')
		return (0);
	if (cell == e->player || cell == e->player + 32)
		return (1);
	return (2);
}

void	put_position(t_env *e, t_pos p)
{
	if (p.y == -100 && p.x == -100)
	{
		ft_putstr("0 0\n");
		mlx_destroy_image(e->mlx, e->img.i);
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	ft_putnbr(p.y);
	ft_putchar(' ');
	ft_putnbr(p.x);
	ft_putchar('\n');
}
