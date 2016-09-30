/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 06:32:25 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/30 19:52:49 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char	*line;
	t_env	e;

	e.m = set_pos(0, 0);
	e.s = set_pos(0, 0);
	e.hd = 0;
	e.vd = 0;
	e.fd = open("test", O_WRONLY);
	if (get_next_line(0, &line) > 0)
	{
		e.player = (line[10] == '1' ? 'O' : 'X');
		free(line);
	}
	while (get_next_line(0, &line) > 0)
	{
		// usleep(500000);
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

// Trouver sa position par rapport à l'adversaire OK
// Determiner le type de piece OK
// Trouver les points sensible pour poser la piece OK
// Trouver le point de destination qui se rapproche le plus de l'adversaire OK
// Trouver la case pour poser notre bloc au plus proche de la destination OK
// Poser la piece OK
// check si on est au dessu de l'ennemi pour placer une piece !
// trouver solution faille dans la muraille
// segfault sur grande map
// Baiser l'ennemi KO
