/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:23:38 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 11:52:48 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_size(char **map)
{
	int		i;
	size_t	size;

	i = 1;
	size = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != size)
			return (-1);
		i++;
	}
	return (0);
}
