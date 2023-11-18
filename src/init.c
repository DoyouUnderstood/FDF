/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:27:41 by alletond          #+#    #+#             */
/*   Updated: 2023/11/18 19:13:39 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_win(t_mlx *mlx, t_map *map)
{
	draw(map, mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->mlx_img, 0, 0);
	mlx_hook(mlx->mlx_win, 17, 0, close_window, NULL);
	//mlx_hook(mlx->mlx_win, , 0, mv_alpha, NULL);
	mlx_loop(mlx->mlx_ptr);
	ft_putstr("sss");

}

t_td	*init_point(void)
{
	t_td *point;
	point = malloc(sizeof(t_td));
	point->x = -1;
	point->y = -1;
	return (point);
}

t_mlx	*init_mlx(t_mlx *mlx)
{
	mlx = malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win_x = 1800;
	mlx->win_y = 1600;
	mlx->max_x = 0;
	mlx->max_y = 0;
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, mlx->win_x, mlx->win_y,
			"SUU");
	mlx->mlx_img = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->addr_img = mlx_get_data_addr(mlx->mlx_img, &mlx->bits_per_pixels,
			&mlx->line_lengts, &mlx->endian);
	return (mlx);
}

void	print_char_matrix(char **matrix)
{
	if (matrix == NULL)
	{
		return ;
	}
	for (int i = 0; matrix[i] != NULL; i++)
	{
		for (int j = 0; matrix[i][j] != '\0'; j++)
		{
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}
}
t_line *init_line(t_line *line)
{
	line = malloc(sizeof(t_line));
	line->x0 = -1;
	line->x1 = -1;
	line->y0 = -1;
	line->y1 = -1;
	return (line);
}

t_map	*init_map(int argc, char **argv)
{
	t_map	*map;
	char	**ptr;
	char	*str;

	ptr = NULL;
	str = NULL;
	map = malloc(sizeof(t_map));
	str = openfile(argc, argv);
	ptr = ft_split(str, '\n');
	free(str);
	map->deep = 0;
	map->len = get_length(ptr);
	map->height = get_height(ptr);
	map->size = map->len * map->height;
	map->alpha = M_PI / 6;
	map->line = init_line(map->line);
	map->mlx = init_mlx(map->mlx);
	map->map = malloc(sizeof(t_point *) * map->height);
	map->coord = malloc(sizeof(t_td *) * map->height);
	fill_map(ptr, map);
	free_str(ptr);
	return (map);
}
