/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:58:40 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/15 18:42:28 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (!(i = ft_strlen(s)))
		return (ft_strdup(s));
	while (s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n')
		i--;
	if ((str = (char*)malloc(sizeof(char) * i)))
		ft_strcpy(str, ft_strsub(s, 0, i));
	return (str);
}
