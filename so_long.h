/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:21:53 by agerbaud          #+#    #+#             */
/*   Updated: 2024/04/01 16:52:41 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# ifndef BONUS
#  define BONUS	0
# endif

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364
# define KEY_Q				113
# define KEY_ESC  			65307

# define IDLE			0
# define FRONT			1
# define LEFT			2
# define RIGHT			3
# define BACK			4

# define FLOOR					"./assets/map/grass.xpm"
# define BUSH					"./assets/map/bush.xpm"
# define WATER					"./assets/map/water.xpm"
# define WATER_R				"./assets/map/water_bottom.xpm"
# define WATER_L				"./assets/map/water_left.xpm"
# define WATER_D				"./assets/map/water_right.xpm"
# define WATER_T				"./assets/map/water_top.xpm"
# define WATER_TR				"./assets/map/water_top_right+.xpm"
# define WATER_TL				"./assets/map/water_top_left+.xpm"
# define WATER_DR				"./assets/map/water_bottom_right+.xpm"
# define WATER_DL				"./assets/map/water_bottom_left+.xpm"
# define GEM					"./assets/map/gem.xpm"
# define PLAYER_FRONT1			"./assets/duck/front1.xpm"
# define PLAYER_FRONT2			"./assets/duck/front2.xpm"
# define PLAYER_FRONT_RIGHT1	"./assets/duck/front_right1.xpm"
# define PLAYER_FRONT_RIGHT2	"./assets/duck/front_right2.xpm"
# define PLAYER_FRONT_LEFT1		"./assets/duck/front_left1.xpm"
# define PLAYER_FRONT_LEFT2		"./assets/duck/front_left2.xpm"
# define PLAYER_IDLE			"./assets/duck/idle.xpm"
# define PLAYER_LEFT1			"./assets/duck/left1.xpm"
# define PLAYER_LEFT2			"./assets/duck/left2.xpm"
# define PLAYER_RIGHT1			"./assets/duck/right1.xpm"
# define PLAYER_RIGHT2			"./assets/duck/right2.xpm"
# define PLAYER_BACK1			"./assets/duck/back1.xpm"
# define PLAYER_BACK2			"./assets/duck/back2.xpm"
# define PLAYER_BACK_RIGHT1		"./assets/duck/back_right1.xpm"
# define PLAYER_BACK_RIGHT2		"./assets/duck/back_right2.xpm"
# define PLAYER_BACK_LEFT1		"./assets/duck/back_left1.xpm"
# define PLAYER_BACK_LEFT2		"./assets/duck/back_left2.xpm"
# define OPEN_EXIT				"./assets/map/exit_open.xpm"
# define EXIT_CLOSED			"./assets/map/exit_closed.xpm"
# define TRAP					"./assets/map/trap.xpm"
# define BOX_CENTER				"./assets/box/center.xpm"
# define BOX_LEFT				"./assets/box/left.xpm"
# define BOX_RIGHT				"./assets/box/right.xpm"
# define ONE_HEART				"./assets/box/one_heart.xpm"
# define TWO_HEART				"./assets/box/two_heart.xpm"
# define THREE_HEART			"./assets/box/three_heart.xpm"

# define KEYPRESS			02
# define KEYPRESSMASK		1L<<0
# define KEYRELEASE			03
# define KEYRELEASEMASK		1L<<1
# define DESTROYNOTIFY		17
# define DESTROYNOTIFYMASK	1L<<17


typedef struct s_coordinate
{
	int	x;
	int	y;
	int	x_start;
	int	y_start;
}	t_coordinate;

typedef struct s_image
{
	char	*buf;
	void	*ptr;
	int		height;
	int		width;
	int		pixel_bits;
	int		line_size;
	int		endian;
}	t_image;

typedef struct s_playerspt
{
	t_image		front1;
	t_image		front2;
	t_image		front_right1;
	t_image		front_right2;
	t_image		front_left1;
	t_image		front_left2;
	t_image		left1;
	t_image		left2;
	t_image		right1;
	t_image		right2;
	t_image		back1;
	t_image		back2;
	t_image		back_right1;
	t_image		back_right2;
	t_image		back_left1;
	t_image		back_left2;
	t_image		idle;
}	t_playerspt;

typedef struct s_map
{
	t_image			img;
	t_image			background;
	char			**full;
	int				rows;
	int				columns;
	int				coins;
	int				exit;
	t_coordinate	player;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		moves_str[17];
	t_map		map;
	t_image		frame;
	t_image		floor;
	t_image		bush;
	t_image		water;
	t_image		water_l;
	t_image		water_r;
	t_image		water_d;
	t_image		water_t;
	t_image		water_dl;
	t_image		water_dr;
	t_image		water_tl;
	t_image		water_tr;
	t_image		gem;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		trap;
	t_image		box_center;
	t_image		box_left;
	t_image		box_right;
	t_image		one_heart;
	t_image		two_heart;
	t_image		three_heart;
	t_playerspt	player;
	int			heart;
	int			open;
	int			up;
	int			down;
	int			left;
	int			right;
	int			count;
}	t_game;

/*GAME*/
t_image	put_img_to_img(t_image src, t_image dst, int x, int y);
void	consumables(t_game *game);
void	render_map(t_game *game);
char	**ft_reader(char *file);
void	render_map(t_game *game);
int		keypress(int keycode, t_game *param);
int		keyrelease(int keycode, t_game *param);
int		actions(t_game *param);
t_image	put_player(t_image src, t_image dst, int x, int y);
int		destroyer(t_game *game);
void	consumables(t_game *game);
void	check_exit(t_game *game);
void	init_frame(t_game *game);
void	put_part_map(t_image src, t_image dst, int x, int y);
void	trap(t_game *game);
int		check_next_move(t_game *game, t_coordinate coord, int move);
t_image	choose_player1(t_game *game);
t_image	choose_player2(t_game *game);
void	free_tab(char **map);

/*CHECK MAP*/
int		ft_check_size(char **map);
int		ft_check_wall(char **map);
int		ft_check_elements(char **map);
int		ft_check_solution(char **map);
int		ft_checker(char **map);
int		count_char(char **map, char c);

/*INIT*/
void	init_mlx_game(t_game *game);
void	init_variables(t_game *game);
void	init_sprites(t_game *game);
void	create_img(t_game *game, t_image *img, int height, int width);

#endif
