/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:52:14 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 12:01:10 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	pf_putnbr_unsigned_fd(unsigned int n, int fd, int *nb_char)
{
	if (n > 9)
	{
		pf_putnbr_fd(n / 10, fd, nb_char);
		pf_putnbr_fd(n % 10, fd, nb_char);
	}
	else if ((*nb_char) >= 0)
		pf_putchar_fd(n + '0', fd, nb_char);
}
