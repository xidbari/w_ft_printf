/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:45:03 by aosman            #+#    #+#             */
/*   Updated: 2025/06/17 16:11:31 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main() {
	int x;

	x = 3;

    int res = ft_printf(" %u ", -1);
	printf("\n");
	int res1 = printf(" %u ", -1);

	printf("\ncount f_printf: %d\n", res);
	printf("count printf: %d\n", res1);
    return (0);
}
