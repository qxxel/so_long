/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:52:54 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 11:52:48 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_exit(t_game *game, int x, int y)
{
	if (game->map.full[(y + 63) / 64][x / 64] == 'O')
		y += 63;
	else if (game->map.full[y / 64][(x + 63) / 64] == 'O')
		x += 63;
	else if (game->map.full[(y + 63) / 64][(x + 63) / 64] == 'O')
	{
		x += 63;
		y += 63;
	}
	if (game->map.full[y / 64][x / 64] == 'O')
	{
		ft_putstr_fd("\nYou won !", 1);
		destroyer(game);
	}
}

void	search_exit(char **map, int **exit)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				(*exit)[0] = i;
				(*exit)[1] = j;
			}
			j++;
		}
		i++;
	}
}

void	exit_opener(t_game *game)
{
	int	*exit;

	if (count_char(game->map.full, 'C') == 0)
	{
		exit = (int *)malloc(2 * sizeof(int));
		if (!exit)
			return ;
		search_exit(game->map.full, &exit);
		game->map.img = put_img_to_img(game->open_exit, game->map.img,
				exit[1], exit[0]);
		game->map.full[exit[0]][exit[1]] = 'O';
		game->open = 1;
		free(exit);
	}
}

void	trap(t_game *game, int *x, int *y)
{
	if (game->map.full[(*y + 63) / 64][*x / 64] == 'T')
		*y += 63;
	else if (game->map.full[*y / 64][(*x + 63) / 64] == 'T')
		*x += 63;
	else if (game->map.full[(*y + 63) / 64][(*x + 63) / 64] == 'T')
	{
		*x += 63;
		*y += 63;
	}
	if (game->map.full[*y / 64][*x / 64] == 'T')
	{
		if (game->heart - 1 == 0)
		{
			ft_putstr_fd("\nYou lose...", 1);
			destroyer(game);
		}
		else
		{
			*x = game->map.player.x_start;
			*y = game->map.player.y_start;
			game->heart--;
		}
	}
}

void	consumables(t_game *game, int x, int y)
{
	if (game->map.full[(y + 63) / 64][x / 64] == 'C')
		y += 63;
	else if (game->map.full[y / 64][(x + 63) / 64] == 'C')
		x += 63;
	else if (game->map.full[(y + 63) / 64][(x + 63) / 64] == 'C')
	{
		x += 63;
		y += 63;
	}
	if (game->map.full[y / 64][x / 64] == 'C')
	{
		game->map.full[y / 64][x / 64] = '0';
		game->map.img = put_img_to_img(game->floor, game->map.img,
				x / 64, y / 64);
		exit_opener(game);
	}
}
