/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:45:03 by aosman            #+#    #+#             */
/*   Updated: 2025/06/17 12:39:46 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main() {
	int x;

	x = 3;

    int res = ft_printf(" %p %p ", 0, 0);
	printf("\n");
	int res1 = printf(" %p %p ", 0, 0);

	printf("count f_printf: %d\n", res);
	printf("count printf: %d\n", res1);
    return (0);
}
