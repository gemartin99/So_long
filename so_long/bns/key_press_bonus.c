/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_w.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:51:33 by marvin            #+#    #+#             */
/*   Updated: 2022/05/23 15:39:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"
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
		if (d->big_line[i - d->width_l] == 'X')
			ft_dead(d);
		d->moves++;
		if (d->big_line[i - d->width_l] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i - d->width_l] = 'P';
		change_sprite(d, 0);
		if (d->npccontrol == 0)
			d->npcstart = d->npcback;
		else
			d->npcstart = d->npcbmv;
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
		if (d->big_line[i + d->width_l] == 'X')
			ft_dead(d);
		d->moves++;
		if (d->big_line[i + d->width_l] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i + d->width_l] = 'P';
		change_sprite(d, 0);
		if (d->npccontrol == 0)
			d->npcstart = d->npc;
		else
			d->npcstart = d->npcmv;
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
		if (d->big_line[i - 1] == 'X')
			ft_dead(d);
		d->moves++;
		if (d->big_line[i - 1] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i - 1] = 'P';
		change_sprite(d, 0);
		if (d->npccontrol == 0)
			d->npcstart = d->npcleft;
		else
			d->npcstart = d->npclmv;
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
		if (d->big_line[i + 1] == 'X')
			ft_dead(d);
		d->moves++;
		if (d->big_line[i + 1] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i + 1] = 'P';
		change_sprite(d, 0);
		if (d->npccontrol == 0)
			d->npcstart = d->npcright;
		else
			d->npcstart = d->npcrmv;
	}
	print_map(d);
}

int	key_press(int key, t_list *d)
{
	char	*moves_p;

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
	mlx_string_put(d->mlx, d->win,
		d->x - 70, d->y - 20, 0x00000, "MOVES:");
	mlx_string_put(d->mlx, d->win,
		d->x - 30, d->y - 20, 0x00000, moves_p);
	write(1, moves_p, ft_strlen(moves_p));
	if (moves_p)
		free(moves_p);
	write(1, "\n", 1);
	return (0);
}
