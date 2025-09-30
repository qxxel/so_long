/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:08:27 by agerbaud          #+#    #+#             */
/*   Updated: 2024/03/29 16:52:01 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_in(char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

static int	check_char(char **map, char *chars)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!is_in(chars, map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	count_char(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_check_elements(char **map)
{
	if (!BONUS)
	{
		if (check_char(map, "01PEC") == 0)
			return (-2);
	}
	else
	{
		if (check_char(map, "01PECT") == 0)
			return (-2);
	}
	if (count_char(map, 'P') != 1)
		return (-1);
	if (count_char(map, 'E') != 1)
		return (-1);
	if (count_char(map, 'C') == 0)
		return (-1);
	return (0);
}
