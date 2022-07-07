/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:27:21 by marvin            #+#    #+#             */
/*   Updated: 2022/05/20 20:06:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	check_map_extension(char *map, t_list *d)
{
	int	i;

	i = ft_strlen(map);
	if (i > 2 && map[i - 4] == '.' && map[i - 3] == 'b'
		&& map[i - 2] == 'e' && map[i - 1] == 'r')
		;
	else
		ft_error(d, 6);
}

void	init_img(t_list *d)
{
	int	img_w;
	int	img_h;

	img_w = 50;
	img_h = 50;
	d->y = (ft_strlen(d->big_line) / d->width_l + 1) * 50;
	d->x = (d->width_l - 1) * 50;
	d->bush = mlx_xpm_file_to_image(d->mlx, "bush.xpm", &img_w, &img_h);
	d->fond = mlx_xpm_file_to_image(d->mlx, "fond.xpm", &img_w, &img_h);
	d->poke = mlx_xpm_file_to_image(d->mlx, "poke.xpm", &img_w, &img_h);
	d->npcstart = mlx_xpm_file_to_image(d->mlx, "npc.xpm", &img_w, &img_h);
	d->npc = mlx_xpm_file_to_image(d->mlx, "npc.xpm", &img_w, &img_h);
	d->npcmv = mlx_xpm_file_to_image(d->mlx, "npcmv.xpm", &img_w, &img_h);
	d->npcleft = mlx_xpm_file_to_image(d->mlx, "npcleft.xpm", &img_w, &img_h);
	d->npclmv = mlx_xpm_file_to_image(d->mlx, "npcleftmv.xpm", &img_w, &img_h);
	d->npcright = mlx_xpm_file_to_image(d->mlx, "npcright.xpm", &img_w, &img_h);
	d->npcrmv = mlx_xpm_file_to_image(d->mlx, "npcrightmv.xpm", &img_w, &img_h);
	d->npcback = mlx_xpm_file_to_image(d->mlx, "npcback.xpm", &img_w, &img_h);
	d->npcbmv = mlx_xpm_file_to_image(d->mlx, "npcbackmv.xpm", &img_w, &img_h);
	d->imgexit = mlx_xpm_file_to_image(d->mlx, "imgexit.xpm", &img_w, &img_h);
}

int	main(int argc, char **argv)
{
	t_list	*d;

	if (argc != 2)
	{
		write(1, "Numero de argumentos incorrecto.\n", 33);
		return (0);
	}
	d = ft_calloc(1, sizeof(t_list));
	if (!d)
		return (0);
	d->mlx = mlx_init();
	init_data(d, argv[1]);
	mlx_key_hook(d->win, key_press, d);
	mlx_hook(d->win, 17, 0, ft_free, d);
	mlx_loop(d->mlx);
	ft_free(d);
	return (0);
}

int	init_data(t_list *d, char *map)
{
	d->moves = 0;
	check_map_extension(map, d);
	read_map(map, d);
	init_img(d);
	d->win = mlx_new_window(d->mlx, d->x, d->y, "so_long");
	print_map(d);
	return (0);
}
