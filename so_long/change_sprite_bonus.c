/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:35:19 by marvin            #+#    #+#             */
/*   Updated: 2022/05/20 19:09:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	change_sprite(t_list *d, int num)
{
	int	change;

	change = 0;
	if (num == 0)
	{
		if (d->npccontrol == 0)
		{
			d->npccontrol = 1;
			change++;
		}
		if (d->npccontrol == 1 && change == 0)
			d->npccontrol = 0;
	}
	if (d->spenemy == 0)
	{
		d->enemyst = d->enemy_;
		d->spenemy = 1;
		change = 2;
	}
	if (d->spenemy == 1 && change != 2)
	{
		d->enemyst = d->enemymv;
		d->spenemy = 0;
	}
}
