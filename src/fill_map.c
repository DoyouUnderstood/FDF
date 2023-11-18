/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:25:01 by alletond          #+#    #+#             */
/*   Updated: 2023/11/18 19:20:24 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	hex_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (10 + c - 'a');
	if (c >= 'A' && c <= 'F')
		return (10 + c - 'A');
	return (0);
}

static int	parse_color(char *color_str)
{
	int	color;

	color = 0;
	while (*color_str && *color_str != ' ')
	{
		color = color * 16 + hex_to_int(*color_str);
		color_str++;
	}
	return (color);
}

static void	parse_line(t_map *map, int row_index, char *line)
{
	int		col_index;
	char	*ptr;

	col_index = 0;
	while (col_index < map->len)
	{
		while (*line == ' ')
			line++;
		if (!*line)
			break ;
		map->map[row_index][col_index].z = ft_atoi(line);
		if (map->map[row_index][col_index].z > map->deep)
			map->deep = map->map[row_index][col_index].z;
		ptr = line;
		while (*ptr && *ptr != ' ' && *ptr != ',')
			ptr++;
		if (*ptr == ',')
		{
			map->map[row_index][col_index].color = parse_color(ptr + 1);
			line = ptr + 1;
		}
		else
		{
			map->map[row_index][col_index].color = 0xFFFFFF;
			line = ptr;
		}
		while (*line && *line != ' ')
			line++;
		col_index++;
	}
}

// scale factor x est egale a 180 mais pe 100 normalement.

void ladder(t_ladder *lad, t_map *map)
{
	lad->map_height = map->height;
	
}
void fill_t_td(t_map *map, int i, int j)
{
    double scale_factor_x, scale_factor_y, scale_factor;
    double offset_x, offset_y;
    double reduction_factor = 0.5;  // Facteur de réduction pour le zoom out

    // Calcul des facteurs d'échelle en tenant compte de la hauteur maximale (Z)
    scale_factor_x = ((map->mlx->win_x / (double)map->len) * reduction_factor) / 8;
    scale_factor_y = ((map->mlx->win_y / (double)map->height) * reduction_factor) / 8;
    double scale_factor_z = map->mlx->win_y / (double)map->deep;  // Nouveau facteur d'échelle pour Z

    // Choisissez le plus petit facteur d'échelle
    scale_factor = fmin(scale_factor_x, fmin(scale_factor_y, scale_factor_z));

    // Ajuster les offsets pour centrer la carte
    offset_x = (map->mlx->win_x - (map->len * scale_factor)) / 2;
    offset_y = (map->mlx->win_y - (map->height * scale_factor)) / 2;

    // Appliquer la mise à l'échelle et les offsets aux coordonnées
    map->coord[i][j].x = ((map->map[i][j].x - map->map[i][j].y) * cos(map->alpha) / sqrt(2)) * scale_factor + offset_x;
    map->coord[i][j].y = ((map->map[i][j].x + map->map[i][j].y) * sin(map->alpha) / sqrt(2) - map->map[i][j].z) * scale_factor + offset_y;
}


void	fill_map(char **array_2d, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		map->coord[i] = malloc(sizeof(t_td) * map->len);
		map->map[i] = malloc(sizeof(t_point) * map->len);
		if (!map->map[i])
		{
			free_t_map(map);
			return ;
		}
		parse_line(map, i, array_2d[i]);
		j = 0;
		while (j < map->len)
		{
			map->map[i][j].x = j;
			map->map[i][j].y = i;
			fill_t_td(map, i, j);
			j++;
		}
		i++;
	}
}
