/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:51:35 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 12:00:42 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	pf_puthexa(unsigned int nbr, char *base, int *nb_char)
{
	unsigned int	base_len;

	base_len = 16;
	if (nbr >= base_len)
	{
		pf_puthexa(nbr / base_len, base, nb_char);
		nbr %= base_len;
	}
	if ((*nb_char) >= 0)
		pf_putchar_fd(base[nbr], 1, nb_char);
}
