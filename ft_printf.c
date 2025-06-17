/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:52:30 by aosman            #+#    #+#             */
/*   Updated: 2025/06/17 15:39:15 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			//printf("got -> %c at i+1 :%i\n", str[i+1], i+1);
			//count += ft_get_params(str[i + 1], args);
			ft_get_params(str[i + 1], args, &count);
			//printf("count : %d", count);
			i += 2;
		}
		else
		{
			count++;
			//printf("%c at i :%i\n", str[i], i);
			ft_putchar_fd(str[i], 1);
			i++;
		}

	}
	va_end(args);

	return (count);
}
