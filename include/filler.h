/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:40:42 by qhonore           #+#    #+#             */
/*   Updated: 2016/10/02 22:00:01 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "mlx.h"

# define NOTIFY_MASK (1L<<17)
# define DESTROYNOTIFY 17

typedef struct s_pos	t_pos;
typedef struct s_img	t_img;
typedef struct s_env	t_env;

struct	s_pos
{
	int		x;
	int		y;
};

struct	s_img
{
	void	*i;
	char	*d;
	int		bpp;
	int		sl;
	int		edn;
};

struct	s_env
{
	void	*mlx;
	void	*win;
	t_img	img;
	char	player;
	t_pos	m;
	t_pos	p;
	t_pos	o;
	t_pos	b;
};

void	play(t_env *e, char map[e->m.y][e->m.x], char piece[e->p.y][e->p.x]);
int		expose_hook(void *env);
void	game_render(t_env *e, char map[e->m.y][e->m.x]);

int		get_map_size(char *line, t_env *e);
void	make_map(t_env *e);

t_pos	set_pos(int x, int y);
int		get_dist(t_pos a, t_pos b);
int		cell_type(t_env *e, char cell);
void	put_position(t_env *e, t_pos p);
int		window_destroyed(void *env);

#endif
