/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:27:29 by agerbaud          #+#    #+#             */
/*   Updated: 2024/02/05 02:27:29 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// -------------------------------------------------

void	create_background(t_game *game)
{
	int	x;
	int	y;

	create_img(game, &game->map.background, 720, 1280);
	y = 0;
	while (y < 12)
	{
		x = 0;
		while (x < 20)
		{
			put_img_to_img(game->water, game->map.background, x, y);
			x++;
		}
		y++;
	}
}

void	ft_identify_sprite(t_game *game, int y, int x)
{
	char	parameter;

	parameter = game->map.full[y][x];
	if (parameter == '1')
		game->map.img = put_img_to_img(game->bush, game->map.img, x, y);
	else if (parameter == '0')
		game->map.img = put_img_to_img(game->floor, game->map.img, x, y);
	else if (parameter == 'C')
		game->map.img = put_img_to_img(game->gem, game->map.img, x, y);
	else if (parameter == 'E')
		game->map.img = put_img_to_img(game->exit_closed, game->map.img, x, y);
	else if (parameter == 'P')
	{
		game->map.img = put_img_to_img(game->floor, game->map.img, x, y);
		game->map.player.x = x * 64;
		game->map.player.y = y * 64;
		game->map.player.x_start = game->map.player.x;
		game->map.player.y_start = game->map.player.y;
	}
	if (BONUS && parameter == 'T')
		game->map.img = put_img_to_img(game->trap, game->map.img, x, y);
}

void	ft_place_limits(t_game *game)
{
	int	i;

	game->map.img = put_img_to_img(game->water_tl, game->map.img, 0, 0);
	game->map.img = put_img_to_img(game->water_dl, game->map.img, 0,
			game->map.rows - 1);
	game->map.img = put_img_to_img(game->water_tr, game->map.img,
			game->map.columns - 1, 0);
	game->map.img = put_img_to_img(game->water_dr, game->map.img,
			game->map.columns - 1, game->map.rows - 1);
	i = 0;
	while (++i < game->map.columns - 1)
		game->map.img = put_img_to_img(game->water_t, game->map.img, i, 0);
	i = 0;
	while (++i < game->map.columns - 1)
		game->map.img = put_img_to_img(game->water_r, game->map.img, i,
				game->map.rows - 1);
	i = 0;
	while (++i < game->map.rows - 1)
		game->map.img = put_img_to_img(game->water_l, game->map.img, 0, i);
	i = 0;
	while (++i < game->map.rows - 1)
		game->map.img = put_img_to_img(game->water_d, game->map.img,
				game->map.columns - 1, i);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	create_background(game);
	ft_place_limits(game);
	y = 1;
	while (y < game->map.rows - 1)
	{
		x = 1;
		while (x < game->map.columns - 1)
		{
			ft_identify_sprite(game, y, x);
			x++;
		}
		y++;
	}
}
