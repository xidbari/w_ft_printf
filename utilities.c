/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:29:42 by aosman            #+#    #+#             */
/*   Updated: 2025/06/17 19:23:17 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_num_length(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n / 10)
	{
		count++;
		n /= 10;
	}
	return (count);
}

void	ft_put_u_nbr_fd(unsigned long n, int fd, int *count)
{
	if (n >= 10)
	{
		ft_put_u_nbr_fd(n / 10, fd, count);
	}
	ft_putchar_fd((n % 10) + '0', fd);
	*count += 1;
}

void	ft_put_nbr_fd(int n, int fd, int *count)
{
	int	neg;

	neg = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		*count += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		neg = 1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
	*count += get_num_length(n) + neg;
}

void	ft_puthex(unsigned long n, int upper, int *count)
{
	char	buf[17];
	char	*base;
	int		i;

	i = 16;
	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	buf[i--] = '\0';
	if (n == 0)
	{
		buf[i--] = '0';
		*count += 1;
	}
	while (n > 0)
	{
		buf[i--] = base[n % 16];
		n /= 16;
		*count += 1;
	}
	ft_putstr_fd(buf + i + 1, 1);
}

void	ft_putptr(void *ptr, int *count)
{
	if (ptr == NULL)
	{
		write (1, "(nil)", 5);
		*count += 5;
	}
	else
	{
		write(1, "0x", 2);
		*count += 2;
		ft_puthex((unsigned long)ptr, 0, count);
	}

}

void	ft_putstr(char *str, int *count)
{
	if (str == NULL)
	{
		write (1, "(null)", 6);
		*count += 6;
	}
	else {
		ft_putstr_fd(str, 1);
		*count += ft_strlen(str);
	}

}
