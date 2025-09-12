/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:19:01 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 11:52:48 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_first_last(char *line)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (0);
	while (line[i])
		i++;
	if (line [i - 1] != '1')
		return (0);
	return (1);
}

static int	check_all(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line [i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_wall(char **map)
{
	int	i;

	i = 1;
	if (check_all(map[0]) == 0)
		return (-1);
	while (map[i])
	{
		if (check_first_last(map[i]) == 0)
			return (-1);
		i++;
	}
	if (check_all(map[i - 1]) == 0)
		return (-1);
	return (0);
}
