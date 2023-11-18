/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:57:27 by alletond          #+#    #+#             */
/*   Updated: 2023/11/18 19:00:17 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define KEY_C 8
#define PI 3.14159265358979323846

// #define ANGLE_INCREMENT (PI / 180)

int	close_window(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	exit(0);
}


void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr_img + (y * data->line_lengts + x * (data->bits_per_pixels
				/ 8));
	*(unsigned int *)dst = color;
}

void draw_line(t_mlx *data, t_td p1, t_td p2, int color) 
{
    int dx = fabsf(p2.x - p1.x), sx = p1.x < p2.x ? 1 : -1;
    int dy = -fabsf(p2.y - p1.y), sy = p1.y < p2.y ? 1 : -1;
    int err = dx + dy, e2;
    int steps = fmax(abs(dx), abs(dy)); // Nombre de pas nécessaire

    while (steps > 0) 
	{
        // Dessiner le pixel
        if (p1.x >= 0 && p1.x < data->win_x && p1.y >= 0 && p1.y < data->win_y) {
            my_mlx_pixel_put(data, p1.x, p1.y, color);
        }
        e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            p1.x += sx;
        }
        if (e2 <= dx) {
            err += dx;
            p1.y += sy;
        }
		steps--;
    }
}



// void draw_line(t_mlx *data, int x0, int y0, int x1, int y1, int color) {

//        draw_line(data, point1.x, point1.y, point2.x, point2.y, color);
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}



void draw_line_between_points(t_mlx *data, t_td point1, t_td point2, int color) 
{
    if (point1.x >= 0 && point1.x < data->win_x && point1.y >= 0 && point1.y < data->win_y) {
        draw_line(data, point1, point2, color);
    }
}

void draw(t_map *map, t_mlx *data) 
{
    int x;
	int y;

	x = 0;
	y = 0;
	// printf("max len : %d max height : %d\n", map->len, map->height);
    while (y < map->height) 
	{
		x = 0;
        while(x < map->len)
		{
            if (x + 1 < map->len) 
                draw_line_between_points(data, map->coord[y][x], map->coord[y][x + 1], map->map[y][x].color);
            if (y + 1 < map->height)
                draw_line_between_points(data, map->coord[y][x], map->coord[y + 1][x], map->map[y][x].color);
			x++;
		}
		y++;
    }
}

int	main(int argc, char **argv)
{
	t_map *map = NULL;
	map = init_map(argc, argv);
	init_win(map->mlx, map);
	exit(0);
}