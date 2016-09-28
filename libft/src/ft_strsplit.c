/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:11:04 by qhonore           #+#    #+#             */
/*   Updated: 2016/01/04 21:11:26 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_words_nb(char const *s, char c)
{
	int		words;

	words = 0;
	if (!s[0])
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			words++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (words);
}

static char	*str_maker(char const *s, char c, int *i)
{
	int		size;
	int		j;
	char	*str;

	size = 0;
	j = *i;
	while (s[*i] != '\0' && s[*i] != c)
	{
		size++;
		*i += 1;
	}
	*i = j;
	j = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (s[*i] != '\0' && s[*i] != c)
	{
		str[j] = s[*i];
		*i += 1;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words = find_words_nb(s, c);
	tab = (char**)malloc(sizeof(char*) * (words + 1));
	if (!tab)
		return (NULL);
	while (words--)
	{
		while (s[i] == c)
			i++;
		tab[j] = str_maker(s, c, &i);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
