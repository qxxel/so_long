# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 11:34:08 by agerbaud          #+#    #+#              #
#    Updated: 2025/09/12 12:14:01 by agerbaud         ###   ########.fr        #
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

CC = cc 

CFLAGS = -Wall -Wextra -Werror -MMD -g3 -D BONUS=1
LFLAGS = -lXext -lX11 -lm

BUILD_DIR = .build

OBJECTS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPENDENCIES = $(SRCS:%.c=$(BUILD_DIR)/%.d)

LIBFT_SRC = $(wildcard $(LIBFTDIR)/*.c) $(wildcard $(LIBFTDIR)/**/*.c)
LIBFT_HDR = $(wildcard $(LIBFTDIR)/*.h) $(wildcard $(LIBFTDIR)/**/*.h)
LIBFT_DEPS = $(LIBFT_SRC) $(LIBFT_HDR)


all: mlx $(NAME)

$(LIBFT): $(LIBFT_DEPS)
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX) $(LFLAGS) -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


mlx:
	$(MAKE) -C $(MLX_DIR) all



-include $(DEPENDENCIES)


clean:
	$(RM) -r $(BUILD_DIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) $@
	$(MAKE) -C $(MLX_DIR) $^

re: fclean all


.PHONY: all clean fclean re mlx