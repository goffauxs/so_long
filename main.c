/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:46:33 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/21 14:35:22 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdio.h>

static void	ft_draw(t_map *m, void *mlx, void *mlx_win, t_data **t)
{
	int	x;
	int	y;

	y = -1;
	while (++y < m->height)
	{
		x = -1;
		while (++x < m->width)
		{
			mlx_put_image_to_window(mlx, mlx_win, t[floor]->img,
					x * t[floor]->img_width, y * t[floor]->img_height);
			if (m->array[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, t[wall]->img,
					x * t[wall]->img_width, y * t[wall]->img_height);
			if (m->array[y][x] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, t[door]->img,
					x * t[door]->img_width, y * t[door]->img_height);
			if (m->array[y][x] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, t[player]->img,
					x * t[player]->img_width, y * t[player]->img_height);
			if (m->array[y][x] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, t[loot]->img,
					x * t[loot]->img_width, y * t[loot]->img_height);
		}
	}
}

static void	ft_try_move(t_params *p)
{
	int dest_y;
	int dest_x;

	dest_y = p->player.y;
	dest_x = p->player.x;
	if (p->player.dir == up && p->player.y - 1 > 0)
		dest_y = p->player.y - 1;
	else if (p->player.dir == down && p->player.y + 1 < p->map.height)
		dest_y = p->player.y + 1;
	else if (p->player.dir == left && p->player.x - 1 > 0)
		dest_x = p->player.x - 1;
	else if (p->player.dir == right && p->player.x + 1 < p->map.width)
		dest_x = p->player.x + 1;
	if (p->map.array[dest_y][dest_x] != '1')
		p->map.array[p->player.y][p->player.x] = '0';
		p->map.array[dest_y][dest_x] = 'P';
}

static void ft_get_player_pos(t_params *p)
{
	int	x;
	int	y;

	y = -1;
	while (++y < p->map.height)
	{
		x = -1;
		while (++x < p->map.width)
		{
			if (p->map.array[y][x] == 'P')
			{
				p->player.x = x;
				p->player.y = y;
			}
		}
	}
}

static int	ft_update(t_params *params)
{
	ft_draw(&params->map, params->mlx, params->mlx_win, &params->tiles);
	return (0);
}

static int ft_move_player(int key, t_params *p)
{
	ft_get_player_pos(p);
	printf("x: %d | y: %d\n", p->player.x, p->player.y);
	if (key == 13)
		p->player.dir = up;
	else if (key == 0)
		p->player.dir = left;
	else if (key == 1)
		p->player.dir = down;
	else if (key == 2)
		p->player.dir = right;
	if (key == 13 || key == 0 || key == 1 || key == 2)
		ft_try_move(p);
	ft_update(p);
	return (0);
}

static void	ft_init_assets(t_data **tiles, void *mlx)
{
	int	i;

	i = 0;
	while (tiles[i])
	{
		tiles[i]->img = mlx_xpm_file_to_image(mlx, tiles[i]->relative_path,
			&tiles[i]->img_width, &tiles[i]->img_height);
		i++;
	}
}

static void	ft_init_paths(t_data **tiles)
{
	int	i;

	i = 0;
	while (i < count)
	{
		tiles[i] = malloc(sizeof(t_data));
		if (!tiles[i])
			return ;
		i++;
	}
	tiles[floor]->relative_path = "floor32.xpm";
	tiles[wall]->relative_path = "wall32.xpm";
	tiles[loot]->relative_path = "loot32.xpm";
	tiles[player]->relative_path = "player32.xpm";
	tiles[door]->relative_path = "door_c32.xpm";
	tiles[count] = NULL;
}

int main(int argc, char *argv[])
{
	t_params	params;

	if (argc == 2)
	{
		if (ft_check_valid(argv[1], &params.map))
		{
			params.player.dir = right;
			params.tiles = malloc(sizeof(t_data *) * (count + 1));
			if (!params.tiles)
				return (0);
			ft_init_paths(&params.tiles);
			params.mlx = mlx_init();
			params.mlx_win = mlx_new_window(params.mlx,
				params.map.width * BLOCK, params.map.height * BLOCK, "test");
			ft_init_assets(&params.tiles, params.mlx);
			mlx_loop_hook(params.mlx, &ft_update, &params);
			mlx_key_hook(params.mlx_win, ft_move_player, &params);
			mlx_loop(params.mlx);
		}
	}
}