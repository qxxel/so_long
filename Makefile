# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 11:34:08 by agerbaud          #+#    #+#              #
#    Updated: 2024/04/02 16:18:04 by agerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFTDIR = libft
MLX_DIR = minilibx-linux
LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
SRCS =	srcs/check_elements.c	\
		srcs/check_size.c		\
		srcs/check_solution.c	\
		srcs/check_wall.c		\
		srcs/checker.c			\
		srcs/init_mlx.c			\
		srcs/key_actions.c		\
		srcs/reader.c			\
		srcs/render_map.c		\
		srcs/so_long.c			\
		srcs/put_img_to_img.c	\
		srcs/create_img.c		\
		srcs/events.c			\
		srcs/destroyer.c		\
		srcs/init_frame.c		\
		srcs/put_part_map.c		\
		srcs/choose_player.c

CC = cc -Wall -Wextra -Werror -MMD -g3 -D BONUS=1
LFLAGS = -lXext -lX11 -lm

OBJECTS = $(SRCS:.c=.o)
DEPENDENCIES = $(SRCS:.c=.d)


all: libft mlx $(NAME)

run:	all
		./$(NAME) map.ber

$(NAME): $(OBJECTS) $(LIBFT) $(MLX)
	$(CC) -o $@ $^ $(LFLAGS)

libft:
	$(MAKE) -C $(LIBFTDIR)

mlx:
	$(MAKE) -C $(MLX_DIR) all

-include $(DEPENDENCIES)

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	$(RM) $(OBJECTS) $(DEPENDENCIES)
	$(MAKE) -C $(LIBFTDIR) $@
	$(MAKE) -C $(MLX_DIR) $@

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) $@

re: fclean all

.PHONY: all clean fclean re libft mlx

