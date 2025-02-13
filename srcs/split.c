/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:27:52 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/04 14:23:46 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	countw(char *s, char c)
{
	int		count;
	bool	insidew;

	count = 0;
	while (*s)
	{
		insidew = false;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			if (!insidew)
			{
				count ++;
				insidew = true;
			}
			s++;
		}
	}
	return (count);
}

static char	*get_nextw(char *s, char c)
{
	static int	cursor;
	char		*nextw;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		cursor++;
	while ((s[cursor + len] != c) && s[cursor + len])
		len ++;
	nextw = malloc ((size_t) len * sizeof (char) +1);
	if (!nextw)
		return (NULL);
	while (s[cursor] == c && s[cursor])
		nextw[i++] = s[cursor++];
	nextw[i] = '\0';
	return (nextw);
}

char	**my_split(char *s, char c)
{
	int		words_count;
	char	**result_tab;
	int		i;

	i = 0;
	words_count = countw(s, c);
	if (!words_count)
		exit(1);
	result_tab = malloc(sizeof(char *) * (size_t)(words_count + 2));
	return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_tab[i] = malloc(sizeof(char));
			if (result_tab[i])
				return (NULL);
			result_tab[i++][0] = '\0';
		}
		result_tab[i++] = get_nextw(s, c);
	}
	result_tab[i] = NULL;
	return (result_tab);
}
