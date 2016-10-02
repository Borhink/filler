/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 06:32:25 by qhonore           #+#    #+#             */
/*   Updated: 2016/10/02 21:43:10 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	game_loop(void *env)
{
	t_env	*e;
	char	*line;

	e = (t_env*)env;
	if (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			if ((!e->m.y || !e->m.x) && !get_map_size(line, e))
				return (0);
			next_line();
			make_map(e);
		}
		free(line);
	}
	return (1);
}

int			main(void)
{
	char	*line;
	t_env	e;

	if (!(e.mlx = mlx_init()))
		return (ft_putstr("Creation of mlx failed.\n"));
	e.m = set_pos(0, 0);
	if (get_next_line(0, &line) > 0)
	{
		e.player = (line[10] == '1' ? 'O' : 'X');
		free(line);
	}
	mlx_loop_hook(e.mlx, game_loop, &e);
	mlx_loop(e.mlx);
	return (0);
}
