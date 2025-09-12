/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:21:50 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 11:52:48 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	update_map(t_game *param)
{
	int	x;
	int	y;

	if (!param->up && !param->down && !param->right && !param->left)
		return (0);
	x = param->map.player.x;
	y = param->map.player.y;
	actions(param);
	trap(param, &param->map.player.x, &param->map.player.y);
	if (!param->open)
		consumables(param, x, y);
	else
		check_exit(param, x, y);
	init_frame(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
		param->frame.ptr, 0, 0);
	mlx_string_put(param->mlx_ptr, param->win_ptr, 12, 23, 0x111111,
		param->moves_str);
	if ((param->up || param->down || param->right || param->left)
		&& (x != param->map.player.x || y != param->map.player.y)
		&& param->count % 64 == 0)
		ft_printf("\r%d", param->count / 64);
	return (0);
}

int	check_extension(char *str)
{
	size_t	len;

	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (len <= 4)
		return (-1);
	if (ft_strncmp(str + len - 4, ".ber", 4) == 0)
		return (0);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || check_extension(argv[1]) == -1)
		return (ft_printf("error: give one .ber to the program"), 0);
	game.map.full = ft_reader(argv[1]);
	if (!game.map.full)
		return (0);
	if (ft_checker(ft_reader(argv[1])) < 0)
		return (0);
	init_variables(&game);
	init_mlx_game(&game);
	init_sprites(&game);
	render_map(&game);
	init_frame(&game);
	ft_putchar_fd('0', 1);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
		game.frame.ptr, 0, 0);
	mlx_string_put(game.mlx_ptr, game.win_ptr, 12, 23, 0x111111, "0 moves");
	mlx_hook(game.win_ptr, KEYPRESS, 1L << KEYPRESSMASK, keypress, &game);
	mlx_hook(game.win_ptr, KEYRELEASE, 1L << KEYRELEASEMASK, keyrelease, &game);
	mlx_hook(game.win_ptr, DESTROYNOTIFY, 1L << DESTROYNOTIFYMASK, close_window,
		&game);
	mlx_loop_hook(game.mlx_ptr, update_map, &game);
	mlx_loop(game.mlx_ptr);
}
