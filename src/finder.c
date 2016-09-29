/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:30:08 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/29 21:53:01 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	write_test(t_env *e)
{
	int		fd = open("test", O_WRONLY);

	ft_putnbr_fd(e->p1.y, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(e->p1.x, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(e->p2.y, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(e->p2.x, fd);
	ft_putchar_fd('\n', fd);
}

void	find_axe_x(t_env *e, char map[e->m.y][e->m.x])
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
	write_test(e);
}
