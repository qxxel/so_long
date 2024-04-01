/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:06:45 by agerbaud          #+#    #+#             */
/*   Updated: 2024/04/01 16:54:43 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_destroyer(t_game *game, t_playerspt *player)
{
	mlx_destroy_image(game->mlx_ptr, player->back1.ptr);
	mlx_destroy_image(game->mlx_ptr, player->back2.ptr);
	mlx_destroy_image(game->mlx_ptr, player->back_left1.ptr);
	mlx_destroy_image(game->mlx_ptr, player->back_left2.ptr);
	mlx_destroy_image(game->mlx_ptr, player->back_right1.ptr);
	mlx_destroy_image(game->mlx_ptr, player->back_right2.ptr);
	mlx_destroy_image(game->mlx_ptr, player->front1.ptr);
	mlx_destroy_image(game->mlx_ptr, player->front2.ptr);
	mlx_destroy_image(game->mlx_ptr, player->front_left1.ptr);
	mlx_destroy_image(game->mlx_ptr, player->front_left2.ptr);
	mlx_destroy_image(game->mlx_ptr, player->front_right1.ptr);
	mlx_destroy_image(game->mlx_ptr, player->front_right2.ptr);
	mlx_destroy_image(game->mlx_ptr, player->right1.ptr);
	mlx_destroy_image(game->mlx_ptr, player->right2.ptr);
	mlx_destroy_image(game->mlx_ptr, player->left1.ptr);
	mlx_destroy_image(game->mlx_ptr, player->left2.ptr);
	mlx_destroy_image(game->mlx_ptr, player->idle.ptr);
}

void	image_destroyer(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->map.img.ptr);
	mlx_destroy_image(game->mlx_ptr, game->map.background.ptr);
	mlx_destroy_image(game->mlx_ptr, game->frame.ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.ptr);
	mlx_destroy_image(game->mlx_ptr, game->water.ptr);
	mlx_destroy_image(game->mlx_ptr, game->trap.ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_closed.ptr);
	mlx_destroy_image(game->mlx_ptr, game->open_exit.ptr);
	mlx_destroy_image(game->mlx_ptr, game->bush.ptr);
	mlx_destroy_image(game->mlx_ptr, game->gem.ptr);
	mlx_destroy_image(game->mlx_ptr, game->water_d.ptr);
	mlx_destroy_image(game->mlx_ptr, game->water_t.ptr);
	mlx_destroy_image(game->mlx_ptr, game->water_r.ptr);
	mlx_destroy_image(game->mlx_ptr, game->water_l.ptr);
	mlx_destroy_image(game->mlx_ptr, game->water_dr.ptr);
	mlx_destroy_image(game->mlx_ptr, game->water_dl.ptr);
	mlx_destroy_image(game->mlx_ptr, game->water_tr.ptr);
	mlx_destroy_image(game->mlx_ptr, game->water_tl.ptr);
	mlx_destroy_image(game->mlx_ptr, game->box_center.ptr);
	mlx_destroy_image(game->mlx_ptr, game->box_left.ptr);
	mlx_destroy_image(game->mlx_ptr, game->box_right.ptr);
	mlx_destroy_image(game->mlx_ptr, game->one_heart.ptr);
	mlx_destroy_image(game->mlx_ptr, game->two_heart.ptr);
	mlx_destroy_image(game->mlx_ptr, game->three_heart.ptr);
}

void	free_tab(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map[i]);
	free(map);
}

int	destroyer(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	image_destroyer(game);
	player_destroyer(game, &game->player);
	mlx_destroy_display(game->mlx_ptr);
	mlx_loop_end(game->mlx_ptr);
	if (game->count > 0)
		ft_printf("\n");
	free_tab(game->map.full);
	free(game);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}
