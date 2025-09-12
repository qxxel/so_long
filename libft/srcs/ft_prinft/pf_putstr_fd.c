/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:11:33 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 12:01:28 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	pf_putstr_fd(char *s, int fd, int *nb_char)
{
	size_t	i;

	if (!s)
	{
		pf_putstr_fd("(null)", 1, nb_char);
		return ;
	}
	i = 0;
	while (s[i] && (*nb_char) >= 0)
	{
		pf_putchar_fd(s[i], fd, nb_char);
		i++;
	}
}
