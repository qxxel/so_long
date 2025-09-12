/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:45:53 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 11:52:48 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_image	choose_player1(t_game *game)
{
	if (game->up && game->left)
		return (game->player.back_left1);
	if (game->up && game->right)
		return (game->player.back_right1);
	if (game->down && game->left)
		return (game->player.front_left1);
	if (game->down && game->right)
		return (game->player.front_right1);
	if (game->up)
		return (game->player.back1);
	if (game->down)
		return (game->player.front1);
	if (game->left)
		return (game->player.left1);
	if (game->right)
		return (game->player.right1);
	return (game->player.idle);
}

t_image	choose_player2(t_game *game)
{
	if (game->up && game->left)
		return (game->player.back_left2);
	if (game->up && game->right)
		return (game->player.back_right2);
	if (game->down && game->left)
		return (game->player.front_left2);
	if (game->down && game->right)
		return (game->player.front_right2);
	if (game->up)
		return (game->player.back2);
	if (game->down)
		return (game->player.front2);
	if (game->left)
		return (game->player.left2);
	if (game->right)
		return (game->player.right2);
	return (game->player.idle);
}
