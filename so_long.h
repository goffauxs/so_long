/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:01:47 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/21 13:22:35 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>

# ifndef BLOCK
#  define BLOCK 32
# endif

typedef struct s_map
{
	int		width;
	int		height;
	char	**array;
}				t_map;

enum e_direction
{
	up,
	down,
	left,
	right
};

typedef struct s_player
{
	int					x;
	int 				y;
	enum e_direction	dir;
}				t_player;

typedef struct s_data
{
	void	*img;
	char	*addr;
	char	*relative_path;
	int		img_width;
	int		img_height;
}				t_data;

enum e_tnames
{
	floor,
	wall,
	door,
	player,
	loot,
	count
};

typedef struct s_params
{
	t_map		map;
	void		*mlx;
	void		*mlx_win;
	t_data		*tiles;
	t_player	player;
}				t_params;

int		ft_check_valid(char *filename, t_map *map);

#endif