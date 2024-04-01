/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:34:51 by agerbaud          #+#    #+#             */
/*   Updated: 2024/03/28 17:10:17 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_image	put_img_to_img(t_image src, t_image dst, int x, int y)
{
	int	width;
	int	x_src;
	int	y_src;

	x *= 256;
	y *= 64;
	width = src.width * 4;
	y_src = 0;
	while (y_src < src.height && y + y_src < dst.height)
	{
		x_src = 0;
		while (x_src < width)
		{
			dst.buf[x + x_src + (y + y_src) * dst.line_size]
				= src.buf[x_src + y_src * src.line_size];
			x_src++;
		}
		y_src++;
	}
	return (dst);
}
