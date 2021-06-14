/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:43:17 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/14 14:06:12 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_fill_array(char *filename, t_map *m)
{
	int		fd;
	int		ret;
	int		j;

	ret = 1;
	j = 0;
	fd = open(filename, O_RDONLY);
	m->array = malloc(sizeof(char *) * (m->height + 1));
	if (!m->array)
		return (0);
	while (ret && ret != -1)
	{
		ret = get_next_line(fd, &m->array[j]);
		j++;
		if (ret == 0)
			break ;
	}
	m->array[j] = NULL;
	close(fd);
	return (1);
}

static size_t	ft_get_width(char *filename)
{
	int		fd;
	char	*line;
	int		ret;
	size_t	len;
	
	fd = open(filename, O_RDONLY);
	get_next_line(fd, &line);
	len = ft_strlen(line);
	ret = 1;
	while (ret && ret != -1)
	{
		ret = get_next_line(fd, &line);
		if (ft_strlen(line) != len)
			return (0);
		if (ret == 0)
			break ;
	}
	free(line);
	close(fd);
	return (len);
}

static size_t	ft_get_height(char *filename)
{
	int		fd;
	char	*line;
	size_t	count;

	count = 1;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		count++;
	free(line);
	close(fd);
	return (count);
}

int	ft_check_valid(char *filename, t_map *map)
{
	map->height = ft_get_height(filename);
	map->width = ft_get_width(filename);
	if (map->height > 0 && map->width > 0)
	{
		return (ft_fill_array(filename, map));
	}
	return (0);
}