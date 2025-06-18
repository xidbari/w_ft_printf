/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_nbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:45:41 by aosman            #+#    #+#             */
/*   Updated: 2025/06/18 12:46:03 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_u_nbr_fd(unsigned long n, int fd, int *count)
{
	if (n >= 10)
	{
		ft_put_u_nbr_fd(n / 10, fd, count);
	}
	ft_putchar_fd((n % 10) + '0', fd);
	*count += 1;
}
