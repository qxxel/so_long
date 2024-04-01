/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:43:01 by agerbaud          #+#    #+#             */
/*   Updated: 2024/03/29 16:45:23 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	put_part_map(t_image src, t_image dst, int x_src, int y_src)
// {
// 	int	width;
// 	int	x;
// 	int	y;

// 	ft_printf("%d - %d --> ", x_src, y_src);
// 	x = x_src * -1 * (x_src < 0);
// 	y = y_src * -1 * (y_src < 0);
// 	x_src = x_src * (x_src >= 0);
// 	y_src = y_src * (y_src >= 0);
// 	ft_printf("%d - %d || %d - %d\n", x_src, y_src, x, y);
// 	width = src.width * 4;
// 	while (y_src < src.height && y < dst.height)
// 	{
// 		while (x_src < width)
// 		{
// 			dst.buf[x + y * dst.line_size]
// 				= src.buf[x_src + y_src * src.line_size];
// 			x_src++;
// 		}
// 		y_src++;
// 	}
// }

void	create_moves_str(char *str, int moves)
{
	int	tmp_nbr;
	int	len;

	tmp_nbr = moves;
	len = (moves == 0);
	while (tmp_nbr)
	{
		tmp_nbr /= 10;
		len++;
	}
	str[len--] = 0;
	if (moves == 0)
		str[0] = '0';
	while (moves)
	{
		str[len--] = moves % 10 + '0';
		moves /= 10;
	}
	ft_strlcat(str, " moves", 17);
}

void	put_heart(t_game *game)
{
	if (game->heart == 3)
		put_part_map(game->three_heart, game->frame, 1145, 9);
	if (game->heart == 2)
		put_part_map(game->two_heart, game->frame, 1145, 9);
	if (game->heart == 1)
		put_part_map(game->one_heart, game->frame, 1145, 9);
}

void	put_box(t_game *game)
{
	int	i;
	int	len;

	i = 9;
	create_moves_str(game->moves_str, game->count / 64);
	len = ft_strlen(game->moves_str);
	put_part_map(game->box_left, game->frame, i, 9);
	i += 3;
	while (len)
	{
		put_part_map(game->box_center, game->frame, i, 9);
		i += 6;
		len--;
	}
	put_part_map(game->box_right, game->frame, i, 9);
}

int	choose_move(t_game *game)
{
	if (game->up && !game->down && !game->right && !game->left)
		return (1);
	if (game->down && !game->up && !game->right && !game->left)
		return (2);
	if (game->left && !game->down && !game->up && !game->right)
		return (3);
	if (game->right && !game->down && !game->left && !game->up)
		return (4);
	return (0);
}

void	init_frame(t_game *game)
{
	static int	i = 0;
	int			x_start;
	int			y_start;

	x_start = 624 - game->map.player.x;
	y_start = 344 - game->map.player.y;
	put_part_map(game->map.background, game->frame, 0, 0);
	put_part_map(game->map.img, game->frame, x_start, y_start);
	put_box(game);
	put_heart(game);
	if (!check_next_move(game, game->map.player, choose_move(game)))
	{
		put_part_map(choose_player1(game), game->frame, 624, 344);
		return ;
	}
	if (i % 128 < 64)
		put_part_map(choose_player1(game), game->frame, 624, 344);
	else
		put_part_map(choose_player2(game), game->frame, 624, 344);
	i++;
}
