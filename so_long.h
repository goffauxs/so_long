/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:01:47 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/16 11:41:16 by sgoffaux         ###   ########.fr       */
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
	int		img_width;
	int		img_height;
}				t_data;

typedef	struct s_assets
{
	t_data	*floor;
	t_data	*wall;
	t_data	*player;
	t_data	*door;
	t_data	*loot;
}				t_assets;

int		ft_check_valid(char *filename, t_map *map);

#endif