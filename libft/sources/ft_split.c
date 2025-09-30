/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:21:57 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/08 17:07:02 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	split_size(char const *s, char c)
{
	size_t	size;

	size = 1;
	while (*s)
	{
		if (*s != c && (!s[1] || s[1] == c))
			size++;
		s++;
	}
	return (size);
}

static bool	create_str(char **split, size_t *i, char const *s, int end)
{
	split[*i] = ft_substr(s, 0, end);
	if (!split[*i])
	{
		free_nptr(2, split);
		return (true);
	}
	(*i)++;
	return (false);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	start;
	size_t	s_len;
	size_t	split_len;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * split_size(s, c));
	if (!split)
		return (NULL);
	s_len = 0;
	start = 0;
	split_len = 0;
	while (s[s_len])
	{
		if (s[s_len++] == c)
			start = s_len;
		else if (!s[s_len] || s[s_len] == c)
			if (create_str(split, &split_len, s + start, s_len - start))
				return (NULL);
	}
	split[split_len] = NULL;
	return (split);
}
