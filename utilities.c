/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:29:42 by aosman            #+#    #+#             */
/*   Updated: 2025/06/17 16:11:45 by aosman           ###   ########.fr       */
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
void	ft_put_u_nbr_fd(unsigned long n, int fd, int *count)
{
	if (n >= 10)
	{
		//*count += 1;
		ft_put_u_nbr_fd(n / 10, fd, count);
		//printf("\ncount : %d\n", *count);
	}

	ft_putchar_fd((n % 10) + '0', fd);
	*count += 1;
	//return (i);
}

void	ft_put_nbr_fd(int n, int fd, int *count)
{
	int 	neg;

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
	//int		count;

	//count = 0;
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
	//return(count);
}

void	ft_putptr(void *ptr, int *count)
{
	//int count;

	//count = 0;
	write(1, "0x", 2);
	*count += 2;
	ft_puthex((unsigned long)ptr, 0, count);
	//return (count);
}
void ft_putstr(char *str, int *count)
{	//printf("i inside _putstr : %i", *i);

	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
}

void	ft_get_params(char param, va_list args, int *count)
{
	//int count = 0;

	if (param == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		*count += 1;
	}
	else if (param == 'd' || param == 'i')
		ft_put_nbr_fd(va_arg(args, int), 1, count);
	else if (param == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (param == 'u')
		ft_put_u_nbr_fd(va_arg(args, unsigned int), 1, count);
	else if (param == 'x')
		ft_puthex(va_arg(args, unsigned int), 0, count);
	else if (param == 'X')
		ft_puthex(va_arg(args, unsigned int), 1, count);
	else if (param == 'p')
		ft_putptr(va_arg(args, void *), count);
	else if (param == '%')
	{
		ft_putchar_fd('%', 1);
		(*count)++;
	}
	//return (*count);
}
