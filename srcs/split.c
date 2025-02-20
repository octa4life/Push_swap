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

char	**my_split(char *s, char c)
{
	char	**tab;
	int		words_count;
	int		i;

	i = 0;
	if (check_quotes(s))
		return (write(2, "Error", 5), NULL);
	words_count = countw(s, c);
	tab = malloc (sizeof(char *) * (words_count + 1));
	if (!words_count || !tab)
		return (NULL);
	while (i < words_count)
	{
		tab[i] = get_nextw(s, c);
		if (!tab[i])
			return (free_tab(tab, i), NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	*get_nextw(char *s, char c)
{
	static int	cursor;
	char		*nextw;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		cursor++;
	if (!s[cursor])
	{
		cursor = 0;
		return (NULL);
	}
	while (s[cursor + len] && s[cursor + len] != c)
		len++;
	nextw = malloc((size_t)(len + 1));
	if (!nextw)
		return (NULL);
	while (i < len)
		nextw[i++] = s[cursor++];
	nextw[i] = '\0';
	if (!s[cursor])
		cursor = 0;
	return (nextw);
}

void	free_split(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
