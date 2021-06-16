/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:46:33 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/16 11:47:27 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdio.h>

static void	ft_update(t_map *m, void *mlx, void *mlx_win, t_assets *a)
{
	int		x;
	int		y;
	void

	y = -1;
	while (++y < m->height)
	{
		x = -1;
		while (++x < m->width)
		{
			if (m->array[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, a->wall->img,
					x * a->wall->img_width, y * a->wall->img_height);
			else if (m->array[y][x] == '0' || m->array[y][x] == 'C' || m->array[y][x] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, a->floor->img,
					x * a->floor->img_width, y * a->floor->img_height);
			if (m->array[y][x] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, a->door->img,
					x * a->door->img_width, y * a->door->img_height);
			if (m->array[y][x] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, a->player->img,
					x * a->player->img_width, y * a->player->img_height);
			if (m->array[y][x] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, a->loot->img,
					x * a->loot->img_width, y * a->loot->img_height);
		}
	}
}

static void	ft_init_assets(t_assets *a, void *mlx)
{
	a->floor = malloc(sizeof(t_data));
	if (!a->floor)
		return ;
	a->wall = malloc(sizeof(t_data));
	if (!a->wall)
		return ;
	a->player = malloc(sizeof(t_data));
	if (!a->player)
		return ;
	a->door = malloc(sizeof(t_data));
	if (!a->door)
		return ;
	a->loot = malloc(sizeof(t_data));
	if (!a->floor)
		return ;
	a->floor->img = mlx_xpm_file_to_image(mlx,
		"floor_tile32.xpm", a->floor->img_width, a->floor->img_height);
	a->wall->img = mlx_xpm_file_to_image(mlx,
		"wall_tile32.xpm", a->wall->img_width, a->wall->img_height);
	a->player->img = mlx_xpm_file_to_image(mlx,
		"character32.xpm", a->player->img_width, a->player->img_height);
	a->door->img = mlx_xpm_file_to_image(mlx,
		"door_closed32.xpm", a->door->img_width, a->door->img_height);
	a->loot->img = mlx_xpm_file_to_image(mlx,
		"loot32.xpm", a->loot->img_width, a->loot->img_height);
}

int main(int argc, char *argv[])
{
	void		*mlx;
	void		*mlx_win;
	t_assets	assets;
	t_map		map;

	if (argc == 2)
	{
		if (ft_check_valid(argv[1], &map))
		{
			mlx = mlx_init();
			mlx_win = mlx_new_window(mlx, map.width * BLOCK, map.height * BLOCK, "test");
			ft_init_assets(&assets, mlx);
			for (int y=0; y < map.height; y++)
			{
				for (int x=0; x < map.width; x++)
				{
					if (map.array[y][x] == '1')
						mlx_put_image_to_window(mlx, mlx_win, wall_tile.img, x * wall_tile.img_width, y * wall_tile.img_height);
					else if (map.array[y][x] == '0' || map.array[y][x] == 'C' || map.array[y][x] == 'P')
						mlx_put_image_to_window(mlx, mlx_win, floor_tile.img, x * floor_tile.img_width, y * floor_tile.img_height);
					if (map.array[y][x] == 'E')
						mlx_put_image_to_window(mlx, mlx_win, door.img, x * door.img_width, y * door.img_height);
					if (map.array[y][x] == 'P')
						mlx_put_image_to_window(mlx, mlx_win, character.img, x * character.img_width, y * character.img_height);
					if (map.array[y][x] == 'C')
						mlx_put_image_to_window(mlx, mlx_win, loot.img, x * loot.img_width, y * loot.img_height);
				}
			}
			mlx_loop(mlx);
		}
	}
}