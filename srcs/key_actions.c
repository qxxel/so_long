/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:51:55 by agerbaud          #+#    #+#             */
/*   Updated: 2024/04/02 17:57:25 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_next_move(t_game *game, t_coordinate coord, int move)
{
	if (move == 0)
		return (2);
	if (move == 1
		&& (game->map.full[(coord.y - 1) / 64][(coord.x / 64)] != '1')
		&& (game->map.full[(coord.y - 1) / 64][(coord.x + 63) / 64] != '1'))
		return (1);
	if (move == 2
		&& (game->map.full[(coord.y + 64) / 64][(coord.x / 64)] != '1')
		&& (game->map.full[(coord.y + 64) / 64][(coord.x + 63) / 64] != '1'))
		return (1);
	if (move == 3
		&& (game->map.full[(coord.y / 64)][(coord.x - 1) / 64] != '1')
		&& (game->map.full[(coord.y + 63) / 64][(coord.x - 1) / 64] != '1'))
		return (1);
	if (move == 4
		&& (game->map.full[(coord.y / 64)][(coord.x + 64) / 64] != '1')
		&& (game->map.full[(coord.y + 63) / 64][(coord.x + 64) / 64] != '1'))
		return (1);
	return (0);
}

int	actions(t_game *param)
{
	if (param->up == 1 && check_next_move(param, param->map.player, 1) == 1)
	{
		param->map.player.y = param->map.player.y - 1;
		param->count++;
	}
	if (param->down == 1 && check_next_move(param, param->map.player, 2) == 1)
	{
		param->map.player.y = param->map.player.y + 1;
		param->count++;
	}
	if (param->left == 1 && check_next_move(param, param->map.player, 3) == 1)
	{
		param->map.player.x = param->map.player.x - 1;
		param->count++;
	}
	if (param->right == 1 && check_next_move(param, param->map.player, 4) == 1)
	{
		param->map.player.x = param->map.player.x + 1;
		param->count++;
	}
	return (0);
}

int	keyrelease(int keycode, t_game *param)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		param->up = 0;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		param->left = 0;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		param->down = 0;
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		param->right = 0;
	return (0);
}

int	keypress(int keycode, t_game *param)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		param->up = 1;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		param->left = 1;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		param->down = 1;
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		param->right = 1;
	if (keycode == KEY_Q || keycode == KEY_ESC)
	{
		ft_putstr_fd("\nWhy did you ragequit ??", 1);
		destroyer(param);
	}
	return (0);
}

int	close_window(t_game *param)
{
	ft_putstr_fd("\nWhy did you ragequit ??", 1);
	destroyer(param);
	return (0);
}
