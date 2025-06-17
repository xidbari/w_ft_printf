/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:45:03 by aosman            #+#    #+#             */
/*   Updated: 2025/06/15 15:49:06 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main() {

  	// Calling function sum() with different number
  	// of arguments
    int r = ft_printf("first :%c, second :%c\n", 'X', 'Y');

    return (r);
}
