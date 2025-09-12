/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:20:09 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 12:00:59 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	pf_putnbr_fd(int n, int fd, int *nb_char)
{
	if (n == -2147483648)
		pf_putstr_fd("-2147483648", fd, nb_char);
	else if (n < 0)
	{
		pf_putchar_fd('-', fd, nb_char);
		n = -n;
	}
	if (n > 9)
	{
		pf_putnbr_fd(n / 10, fd, nb_char);
		pf_putnbr_fd(n % 10, fd, nb_char);
	}
	else if (n >= 0 && (*nb_char) >= 0)
		pf_putchar_fd(n + '0', fd, nb_char);
}
