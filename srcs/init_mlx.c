/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:20:15 by agerbaud          #+#    #+#             */
/*   Updated: 2024/01/26 11:20:15 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_variables(t_game *game)
{
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.columns = ft_strlen(game->map.full[0]);
	game->map.rows = ft_tablen(game->map.full);
	game->open = 0;
	game->count = 0;
	game->up = 0;
	game->down = 0;
	game->left = 0;
	game->right = 0;
	game->heart = 3;
	game->moves_str[0] = '\0';
}

void	init_mlx_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1280, 720, "so_long");
	create_img(game, &game->map.img, (ft_tablen(game->map.full)) * 64,
		(ft_strlen(game->map.full[0])) * 64);
	create_img(game, &game->frame, 720, 1280);
}

t_image	create_sprite(void *mlx, char *path)
{
	t_image	sprite;

	sprite.width = 0;
	sprite.height = 0;
	sprite.ptr = mlx_xpm_file_to_image(mlx, path,
			&sprite.width, &sprite.height);
	if (sprite.ptr)
		sprite.buf = mlx_get_data_addr(sprite.ptr, &sprite.pixel_bits,
				&sprite.line_size, &sprite.endian);
	return (sprite);
}

void	init_player_sprites(t_game *game, t_playerspt *player)
{
	player->front1 = create_sprite(game->mlx_ptr, PLAYER_FRONT1);
	player->front2 = create_sprite(game->mlx_ptr, PLAYER_FRONT2);
	player->front_right1 = create_sprite(game->mlx_ptr, PLAYER_FRONT_RIGHT1);
	player->front_right2 = create_sprite(game->mlx_ptr, PLAYER_FRONT_RIGHT2);
	player->front_left1 = create_sprite(game->mlx_ptr, PLAYER_FRONT_LEFT1);
	player->front_left2 = create_sprite(game->mlx_ptr, PLAYER_FRONT_LEFT2);
	player->left1 = create_sprite(game->mlx_ptr, PLAYER_LEFT1);
	player->left2 = create_sprite(game->mlx_ptr, PLAYER_LEFT2);
	player->right1 = create_sprite(game->mlx_ptr, PLAYER_RIGHT1);
	player->right2 = create_sprite(game->mlx_ptr, PLAYER_RIGHT2);
	player->back1 = create_sprite(game->mlx_ptr, PLAYER_BACK1);
	player->back2 = create_sprite(game->mlx_ptr, PLAYER_BACK2);
	player->back_right1 = create_sprite(game->mlx_ptr, PLAYER_BACK_RIGHT1);
	player->back_right2 = create_sprite(game->mlx_ptr, PLAYER_BACK_RIGHT2);
	player->back_left1 = create_sprite(game->mlx_ptr, PLAYER_BACK_LEFT1);
	player->back_left2 = create_sprite(game->mlx_ptr, PLAYER_BACK_LEFT2);
	player->idle = create_sprite(game->mlx_ptr, PLAYER_IDLE);
}

void	init_sprites(t_game *game)
{
	game->floor = create_sprite(game->mlx_ptr, FLOOR);
	game->bush = create_sprite(game->mlx_ptr, BUSH);
	game->water = create_sprite(game->mlx_ptr, WATER);
	game->water_d = create_sprite(game->mlx_ptr, WATER_D);
	game->water_r = create_sprite(game->mlx_ptr, WATER_R);
	game->water_t = create_sprite(game->mlx_ptr, WATER_T);
	game->water_l = create_sprite(game->mlx_ptr, WATER_L);
	game->water_dl = create_sprite(game->mlx_ptr, WATER_DL);
	game->water_dr = create_sprite(game->mlx_ptr, WATER_DR);
	game->water_tl = create_sprite(game->mlx_ptr, WATER_TL);
	game->water_tr = create_sprite(game->mlx_ptr, WATER_TR);
	game->gem = create_sprite(game->mlx_ptr, GEM);
	game->open_exit = create_sprite(game->mlx_ptr, OPEN_EXIT);
	game->exit_closed = create_sprite(game->mlx_ptr, EXIT_CLOSED);
	game->trap = create_sprite(game->mlx_ptr, TRAP);
	game->box_center = create_sprite(game->mlx_ptr, BOX_CENTER);
	game->box_left = create_sprite(game->mlx_ptr, BOX_LEFT);
	game->box_right = create_sprite(game->mlx_ptr, BOX_RIGHT);
	game->one_heart = create_sprite(game->mlx_ptr, ONE_HEART);
	game->two_heart = create_sprite(game->mlx_ptr, TWO_HEART);
	game->three_heart = create_sprite(game->mlx_ptr, THREE_HEART);
	init_player_sprites(game, &game->player);
}
