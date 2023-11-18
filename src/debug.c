/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:16:48 by alletond          #+#    #+#             */
/*   Updated: 2023/11/15 13:04:39 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_t_mlx(t_mlx *data)
{
	if (data == NULL)
	{
		printf("t_mlx is NULL\n");
		return ;
	}
	printf("t_mlx:\n");
	printf("  mlx_ptr: %p\n", data->mlx_ptr);
	printf("  mlx_win: %p\n", data->mlx_win);
	printf("  mlx_img: %p\n", data->mlx_img);
	printf("  size_x: %d\n", data->win_x);
	printf("  size_y: %d\n", data->win_y);
	printf("  endian: %d\n", data->endian);
	printf("  bits_per_pixels: %d\n", data->bits_per_pixels);
	printf("  line_lengts: %d\n", data->line_lengts);
	printf("  addr_img: %p\n", data->addr_img);
}

void	print_t_map(t_map *map)
{
	if (map == NULL)
	{
		printf("t_map is NULL\n");
		return ;
	}
	printf("t_map:\n");
	printf("  height: %d\n", map->height);
	printf("  len: %d\n", map->len);
	printf("  size: %d\n", map->size);
	printf("  alpha: %f\n", map->alpha);
	printf("  map: %p\n", map->map);
	printf("  mlx: %p\n", map->mlx);
	printf("  coord: %p\n", map->coord);
	// Si vous voulez également imprimer le contenu de map->mlx
	print_t_mlx(map->mlx);
}
