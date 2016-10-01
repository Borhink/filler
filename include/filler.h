/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:40:42 by qhonore           #+#    #+#             */
/*   Updated: 2016/10/01 15:03:36 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct s_pos	t_pos;
typedef struct s_env	t_env;

struct	s_pos
{
	int		x;
	int		y;
};

struct	s_env
{
	char	player;
	t_pos	m;// Map size
	t_pos	p;// Piece size
	t_pos	o;// piece Offset
	t_pos	s;// player1 Start (Si x = -1 && y = 1, on doit aller a gauche et en bas)
	t_pos	p1;// Pos player 1
	t_pos	p2;// Pos player 2
	t_pos	d;// Dest
	int		a;// Axe destination
	int		hd;// Horizontal Dest (0 = non atteint, 1 = atteint)
	int		vd;// Vertical Dest
	t_pos	b;// actual Best position
	t_pos	sb;// Substitue to the Best position
	t_pos	bp;// best Piece position
	int		fd;
};

void	find_axe_x(t_env *e, char map[e->m.y][e->m.x]);
void	find_axe_y(t_env *e, char map[e->m.y][e->m.x]);
void	find_piece_best(t_env *e, char piece[e->p.y][e->p.x]);
void	play(t_env *e, char map[e->m.y][e->m.x], char piece[e->p.y][e->p.x]);

void	get_map_size(char *line, t_env *e);
void	make_map(t_env *e);

t_pos	set_pos(int x, int y);
void	next_line(void);
int		get_dist(t_pos a, t_pos b);
int		cell_type(t_env *e, char cell);
int		piece_type(t_env *e, char piece[e->p.y][e->p.x]);

#endif
