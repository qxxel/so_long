/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:04:49 by agerbaud          #+#    #+#             */
/*   Updated: 2024/03/26 17:14:39 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_img(t_game *game, t_image *img, int height, int width)
{
	img->width = width;
	img->height = height;
	if (width > 32767 || height > 32767 || width * height > 536107716)
	{
		img->ptr = NULL;
		return ;
	}
	img->ptr = mlx_new_image(game->mlx_ptr, width, height);
	if (img->ptr)
	{
		img->buf = mlx_get_data_addr(img->ptr, &img->pixel_bits,
				&img->line_size, &img->endian);
	}
}
