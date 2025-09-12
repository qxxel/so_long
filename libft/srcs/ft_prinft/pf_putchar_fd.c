/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:44:16 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 11:57:58 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	pf_putchar_fd(char c, int fd, int *nb_char)
{
	char	c_unsigned;

	if ((*nb_char) < 0)
		return ;
	c_unsigned = (unsigned char)c;
	if (write(fd, &c_unsigned, 1) < 0)
	{
		(*nb_char) = -1;
		return ;
	}
	(*nb_char)++;
}
