/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:00:55 by marvin            #+#    #+#             */
/*   Updated: 2022/05/18 23:03:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_free(t_list *d)
{
	d->errors = 1;
	if (d->big_line)
		free(d->big_line);
	if (d)
		free(d);
	exit(0);
}

void	ft_dead(t_list *d)
{
	write(1, "Te ha matado el enemigo 💀\n", 29);
	ft_free(d);
}
