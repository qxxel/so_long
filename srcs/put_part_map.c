/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_part_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:06:25 by agerbaud          #+#    #+#             */
/*   Updated: 2024/03/28 18:07:05 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_pixel(char *src, char *dst)
{
	if (!src[0])
		return ;
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
	dst[3] = src[3];
}

void	put_part_map(t_image src, t_image dst, int x, int y)
{
	int	x_src;
	int	y_src;

	y_src = y * -1 * (y < 0);
	while (y_src < src.height && y + y_src < dst.height)
	{
		x_src = x * -1 * (x < 0);
		while (x_src < src.width && x + x_src < dst.width)
		{
			put_pixel(&src.buf[x_src * 4 + y_src * src.line_size],
				&dst.buf[(x + x_src) * 4 + (y + y_src) * dst.line_size]);
			x_src++;
		}
		y_src++;
	}
}
