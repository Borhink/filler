/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:54:36 by qhonore           #+#    #+#             */
/*   Updated: 2016/05/12 15:16:09 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_fd(t_dlist **file, int fd)
{
	if (*file)
	{
		while ((*file)->back)
			*file = (*file)->back;
		while ((int)((*file)->content_size) != fd && (*file)->next)
			*file = (*file)->next;
		if ((int)((*file)->content_size) == fd)
			return (1);
		if (!((*file)->next = (t_dlist*)malloc(sizeof(t_dlist))))
			return (0);
		(*file)->next->back = *file;
		*file = (*file)->next;
	}
	else
	{
		if (!(*file = (t_dlist*)malloc(sizeof(t_dlist))))
			return (0);
		(*file)->back = NULL;
	}
	(*file)->next = NULL;
	(*file)->content_size = fd;
	(*file)->content = NULL;
	return (1);
}

static int	get_prev_read(t_dlist *file, char **line)
{
	char	*tmp;
	char	*tmp2;
	char	*str;

	if (!file->content)
		return (0);
	str = (char*)(file->content);
	if ((tmp2 = ft_strchr(str, '\n')))
	{
		*line = ft_strsub(str, 0, (int)(tmp2 - str));
		if (ft_strlen(++tmp2))
			tmp = ft_strdup(tmp2);
		else
			tmp = NULL;
		free(file->content);
		file->content = (void*)tmp;
	}
	else if (ft_strlen(str))
	{
		*line = str;
		file->content = NULL;
	}
	return (tmp2 ? 1 : 0);
}

static int	read_line(char *buf, t_dlist *file, char **line)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	if ((tmp2 = ft_strchr(buf, '\n')))
	{
		tmp3 = ft_strsub(buf, 0, (int)(tmp2 - buf));
		tmp = ft_strjoin(*line, tmp3);
		free(tmp3);
		if (ft_strlen(++tmp2))
			file->content = (void*)ft_strdup(tmp2);
	}
	else
		tmp = ft_strjoin(*line, buf);
	if (*line)
		free(*line);
	*line = tmp;
	if (tmp2)
		return (1);
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static t_dlist	*file = NULL;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	if (!check_fd(&file, fd))
		return (-1);
	if (get_prev_read(file, line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (read_line(buf, file, line))
			break ;
	}
	if (ret == 0)
		ft_dlstndel(&file, 1, 1);
	return (ret > 0 || *line ? 1 : ret);
}
