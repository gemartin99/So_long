/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_w.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:51:33 by marvin            #+#    #+#             */
/*   Updated: 2022/05/20 19:31:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"

void	move_w(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i - d->width_l] != '1'
		&& !check_exit(d, d->big_line[i - d->width_l]))
	{
		d->moves++;
		if (d->big_line[i - d->width_l] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i - d->width_l] = 'P';
		if (d->npccontrol == 0)
		{
			d->npcstart = d->npcback;
			d->npccontrol = 1;
		}
		else
		{
			d->npcstart = d->npcbmv;
			d->npccontrol = 0;
		}
	}
	print_map(d);
}

void	move_s(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i + d->width_l] != '1'
		&& !check_exit(d, d->big_line[i + d->width_l]))
	{
		d->moves++;
		if (d->big_line[i + d->width_l] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i + d->width_l] = 'P';
		if (d->npccontrol == 0)
		{
			d->npcstart = d->npc;
			d->npccontrol = 1;
		}
		else
		{
			d->npcstart = d->npcmv;
			d->npccontrol = 0;
		}
	}
	print_map(d);
}

void	move_a(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i - 1] != '1' && !check_exit(d, d->big_line[i - 1]))
	{
		d->moves++;
		if (d->big_line[i - 1] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i - 1] = 'P';
		if (d->npccontrol == 0)
		{
			d->npcstart = d->npcleft;
			d->npccontrol = 1;
		}
		else
		{
			d->npcstart = d->npclmv;
			d->npccontrol = 0;
		}
	}
	print_map(d);
}

void	move_d(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i + 1] != '1' && !check_exit(d, d->big_line[i + 1]))
	{
		d->moves++;
		if (d->big_line[i + 1] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i + 1] = 'P';
		if (d->npccontrol == 0)
		{
			d->npcstart = d->npcright;
			d->npccontrol = 1;
		}
		else
		{
			d->npcstart = d->npcrmv;
			d->npccontrol = 0;
		}
	}
	print_map(d);
}

int	key_press(int key, t_list *d)
{
	char	*moves_p;

	(void)d;
	if (key == 53)
	{
		mlx_destroy_window(d->mlx, d->win);
		ft_free(d);
	}
	if (key == 13)
		move_w(d);
	if (key == 0)
		move_a(d);
	if (key == 1)
		move_s(d);
	if (key == 2)
		move_d(d);
	moves_p = ft_itoa(d->moves);
	write(1, moves_p, ft_strlen(moves_p));
	if (moves_p)
		free(moves_p);
	write(1, "\n", 1);
	return (0);
}
