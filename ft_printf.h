/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:12:50 by aosman            #+#    #+#             */
/*   Updated: 2025/06/17 11:30:06 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

int ft_printf(const char *str, ...);
int	ft_get_params(char param, va_list args);
int	ft_putptr(void *ptr);
int	ft_puthex(unsigned long n, int upper);
int	ft_put_nbr_fd(int n, int fd);
int	ft_put_u_nbr_fd(unsigned int n, int fd);
int ft_putstr(char *str);
#endif
