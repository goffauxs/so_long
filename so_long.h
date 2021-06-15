/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:01:47 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/15 14:50:40 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>

# ifndef BLOCK
#  define BLOCK 8
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

int		ft_check_valid(char *filename, t_map *map);

#endif