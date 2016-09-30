/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:10:34 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/30 10:34:48 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

int		cell_type(t_env *e, char cell)
{
	if (cell == '.')
		return (0);
	if (cell == e->player || cell == e->player + 32)
		return (1);
	return (2);
}

int		piece_type(t_env *e, char piece[e->p.y][e->p.x])
{
	t_pos	p;
	t_pos	min;
	t_pos	max;

	p.y = -1;
	min = set_pos(e->p.x, e->p.y);
	max = set_pos(0, 0);
	while (++p.y < e->p.y)
	{
		p.x = -1;
		while (++p.x < e->p.x)
			if (piece[p.y][p.x] == '*')
			{
				if (max.x < p.x)
					max.x = p.x;
				if (max.y < p.y)
					max.y = p.y;
				if (min.x > p.x)
					min.x = p.x;
				if (min.y > p.y)
					min.y = p.y;
			}
	}
	return (max.x - min.x >= max.y - min.y ? 1 : 0);
}
