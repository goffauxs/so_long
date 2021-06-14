/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:46:33 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/14 14:46:31 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*addr;
	t_map	map;

	relative_path = "jawbreaker_tiles.xpm";
	if (argc == 2)
	{
		if (ft_check_valid(argv[1], &map))
		{
			mlx = mlx_init();
			mlx_win = mlx_new_window(mlx, map.width * BLOCK, map.height * BLOCK, "test");
			img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
			addr = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
			mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
			mlx_loop(mlx);
		}
	}
}