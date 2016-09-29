/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 06:32:25 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/29 21:51:32 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char	*line;
	t_env	e;

	e.m = set_pos(0, 0);
	e.s = set_pos(0, 0);
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
