/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:29:42 by aosman            #+#    #+#             */
/*   Updated: 2025/06/17 12:47:11 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_num_length(int n)
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
int	ft_put_u_nbr_fd(unsigned int n, int fd)
{
	static int	count = 1;

	if (n >= 10)
	{
		count++;
		ft_put_u_nbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
	return (count);
}

int	ft_put_nbr_fd(int n, int fd)
{
	int 	neg;

	neg = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (11);
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
	return (get_num_length(n) + neg);
}

int	ft_puthex(unsigned long n, int upper)
{
	char	buf[17];
	char	*base;
	int		i;
	int		count;

	count = 0;
	i = 16;
	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	buf[i--] = '\0';
	if (n == 0)
	{
		buf[i--] = '0';
		count++;
	}
	while (n > 0)
	{
		buf[i--] = base[n % 16];
		n /= 16;
		count++;
	}
	ft_putstr_fd(buf + i + 1, 1);
	return(count);
}

int	ft_putptr(void *ptr)
{
	int count;
	(void)((char*)(ptr) == (ptr));

	count = 0;
	write(1, "0x", 2);
	count += 2;
	count += ft_puthex((unsigned long)ptr, 0);
	return (count);
}
int ft_putstr(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_get_params(char param, va_list args)
{
	int count = 0;

	if (param == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		count++;
	}
	else if (param == 'd' || param == 'i')
		count += ft_put_nbr_fd(va_arg(args, int), 1);
	else if (param == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (param == 'u')
		count += ft_put_u_nbr_fd(va_arg(args, unsigned int), 1);
	else if (param == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (param == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (param == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (param == '%')
	{
		ft_putchar_fd('%', 1);
		count++;
	}
	return (count);
}
