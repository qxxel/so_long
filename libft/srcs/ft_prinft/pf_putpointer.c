/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:51:35 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 12:01:17 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	pf_putpointer(unsigned long long nbr, int *nb_char, int first)
{
	unsigned long long	base_len;
	char				*base;

	if (!nbr)
	{
		pf_putstr_fd("(nil)", 1, nb_char);
		return ;
	}
	base_len = 16;
	base = "0123456789abcdef";
	if (first == 1)
	{
		pf_putstr_fd("0x", 1, nb_char);
		first = 0;
	}
	if (nbr >= base_len)
	{
		pf_putpointer(nbr / base_len, nb_char, first);
		nbr %= base_len;
	}
	if ((*nb_char) >= 0)
		pf_putchar_fd(base[nbr], 1, nb_char);
}
