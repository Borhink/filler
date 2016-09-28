/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 06:32:25 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/28 11:39:06 by qhonore          ###   ########.fr       */
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
		e->mapy = ft_atoi(++tmp);
		tmp = ft_strchr(tmp, ' ');
		e->mapx = ft_atoi(++tmp);
	}
	free(line);
}

void	play_turn(t_env *e, int fd)
{
	char	map[e->mapy][e->mapx];
	char	*line;
	int		x;
	int		y;

	y = -1;
	while (++y < e->mapy)
	{
		get_next_line(0, &line);
		x = -1;
		while (++x < e->mapx)
			map[y][x] = line[x + 4];
	}
	y = -1;
	while (++y < e->mapy)
	{
		x = -1;
		while (++x < e->mapx)
			ft_putchar_fd(map[y][x], fd);
		ft_putchar_fd('\n', fd);
	}
}

int		main(void)
{
	char	*line;
	int		fd;
	t_env	e;

	e.mapy = 0;
	e.mapx = 0;
	if ((fd = open("test", O_WRONLY)) > 0)
	{
		if (get_next_line(0, &line) > 0)
		{
			e.player = (line[10] == '1' ? 'O' : 'X');
												ft_putchar_fd(e.player, fd);
												ft_putstr_fd(" <- player\n", fd);
			free(line);
		}
		while (get_next_line(0, &line) > 0)
		{
			if (ft_strstr(line, "Plateau"))
			{
				if (!e.mapy || !e.mapx)
					get_map_size(line, &e);
												ft_putnbr_fd(e.mapy, fd);
												ft_putstr_fd(" <- mapy\n", fd);
												ft_putnbr_fd(e.mapx, fd);
												ft_putstr_fd(" <- mapx\n", fd);
				next_line();
				play_turn(&e, fd);
				ft_putstr("0 0\n");
			}
			else
			{
				ft_putstr_fd(line, fd);
				ft_putstr_fd("\n", fd);
			}
		}
	}
	return (0);
}
