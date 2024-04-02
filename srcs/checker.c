/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:37:58 by agerbaud          #+#    #+#             */
/*   Updated: 2024/04/02 18:11:18 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_checker(char **map)
{
	if (!map)
		return (-1);
	if (map[0] == NULL)
		return (ft_printf("error: empty map or read error"), -1);
	if (ft_check_size(map) < 0)
		return (ft_printf("error: the map is not rectangular"), -1);
	if (ft_check_wall(map) < 0)
		return (ft_printf("error: the map is not closed"), -1);
	if (ft_check_elements(map) == -1)
		return (ft_printf("error: there is'nt the good number of elements"),
			-1);
	if (ft_check_elements(map) == -2)
		return (ft_printf("error: there are unknowns characters"), -1);
	if (ft_check_solution(map) < 0)
		return (ft_printf("error: there is no solution"), -1);
	free_tab(map);
	return (0);
}
