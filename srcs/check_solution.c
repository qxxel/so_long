/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:17:50 by agerbaud          #+#    #+#             */
/*   Updated: 2024/04/01 15:51:11 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_c(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

int	*search_p(char **map)
{
	int	i;
	int	j;
	int	*tab;

	j = 0;
	tab = (int *)malloc(sizeof(int) * 2);
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				return (tab[0] = j, tab[1] = i, tab);
			i++;
		}
		j++;
	}
	return (free (tab), NULL);
}

void	backtracking(char **map, int y, int x, int count[2])
{
	if (map[y][x] == 'E')
		count[1]--;
	if (map[y][x] == 'C')
		count[0]--;
	map[y][x] = '1';
	if (map[y][x + 1] != '1' && (count[0] != 0 || count[1] != 0))
		backtracking(map, y, x + 1, count);
	if (map[y][x - 1] != '1' && (count[0] != 0 || count[1] != 0))
		backtracking(map, y, x - 1, count);
	if (map[y + 1][x] != '1' && (count[0] != 0 || count[1] != 0))
		backtracking(map, y + 1, x, count);
	if (map[y - 1][x] != '1' && (count[0] != 0 || count[1] != 0))
		backtracking(map, y - 1, x, count);
}

int	ft_check_solution(char **map)
{
	char	**tmp_map;
	int		*pos;
	int		count[2];

	tmp_map = map;
	pos = search_p(tmp_map);
	count[0] = count_c(tmp_map);
	count[1] = 1;
	backtracking(tmp_map, pos[0], pos[1], count);
	if (count[0] != 0 || count[1] != 0)
		return (free (pos), -1);
	free (pos);
	return (0);
}
