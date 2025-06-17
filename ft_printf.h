/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:12:50 by aosman            #+#    #+#             */
/*   Updated: 2025/06/17 16:04:25 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "libft.h"

int 	ft_printf(const char *str, ...);
void	ft_get_params(char param, va_list args, int *i);
void	ft_putptr(void *ptr, int *count);
void	ft_puthex(unsigned long n, int upper, int *count);
void	ft_put_nbr_fd(int n, int fd, int *count);
void	ft_put_u_nbr_fd(unsigned long n, int fd, int *count);
void	ft_putstr(char *str, int *count);

#endif
