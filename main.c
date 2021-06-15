/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:46:33 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/15 15:05:16 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		img_width;
	int		img_height;
}				t_data;

int main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;
	t_data	floor_tile;
	t_data	wall_tile;
	t_data	character;
	t_map	map;

	if (argc == 2)
	{
		if (ft_check_valid(argv[1], &map))
		{
			mlx = mlx_init();
			mlx_win = mlx_new_window(mlx, map.width * BLOCK, map.height * BLOCK, "test");
			floor_tile.img = mlx_xpm_file_to_image(mlx, "floor_tile.xpm", &floor_tile.img_width, &floor_tile.img_height);
			wall_tile.img = mlx_xpm_file_to_image(mlx, "wall_tile.xpm", &wall_tile.img_width, &wall_tile.img_height);
			character.img = mlx_xpm_file_to_image(mlx, "character.xpm", &character.img_width, &character.img_height);
			for (int y=0; y < map.height; y++)
			{
				for (int x=0; x < map.width; x++)
				{
					if (map.array[y][x] == '1')
						mlx_put_image_to_window(mlx, mlx_win, wall_tile.img, x * BLOCK, y * BLOCK);
					else if (map.array[y][x] == '0' || map.array[y][x] == 'C' || map.array[y][x] == 'P')
						mlx_put_image_to_window(mlx, mlx_win, floor_tile.img, x * BLOCK, y * BLOCK);
					if (map.array[y][x] == 'P')
						mlx_put_image_to_window(mlx, mlx_win, character.img, x * BLOCK, y * BLOCK);
				}
			}
			mlx_loop(mlx);
		}
	}
}