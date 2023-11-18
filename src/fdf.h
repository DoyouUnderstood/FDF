/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:05:10 by alletond          #+#    #+#             */
/*   Updated: 2023/11/18 19:13:16 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// elemt fract et julia ne repondent pas

#ifndef FDF_H
# define FDF_H

# include "../lib/GNL/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <sys/stat.h>

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}			t_point;

typedef struct s_td
{
	float	x;
	float	y;
}			t_td;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	int		win_y;
	int		win_x;
	int		max_x;
	int		max_y;
	int		endian;
	int		bits_per_pixels;
	int		line_lengts;
	char	*addr_img;

}			t_mlx;

typedef struct s_line
{
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		dx;
	int		dy;
	int		x;
	int		y;
	bool	steep;
	int		error;
	int		ystep;
	int		xstep;
}			t_line;

typedef struct s_ladder
{
	double	scale_factor_x; //facteurs d'échelle individuels axe X.
	double	scale_factor_y;	//facteurs d'échelle individuels axe Y.
	double	scale_factor; // le plus petit des deux facteurs d'echelle.
	double	offset_x;	//centrer au niveau X.
	double	offset_y;	// centrer au niveau Y.
	double	reduction_factor; // pour le zoom.
	int		win_x; // longueur de la fenetre (x).
	int		win_y;	// largeur de la fenetre (y).
	int		map_len;	// longueur de la map FDF(x).
	int		map_height;	// largeur de la map FDF(y).
	int		map_width; // profondeur de la map FDF(z).
}			t_ladder;

typedef struct s_map
{
	int		height;
	int		len;
	int		size;
	float	alpha;
	int		deep; // profondeur max (z)
	int		color;
	t_point	**map;
	t_mlx	*mlx;
	t_line	*line;
	t_td	**coord;
}			t_map;

// open and fill the fill.txt

int			mv_alpha(int keycode, void *param);

char		*openfile(int argc, char **argv);
void		print_2d_char_array(char **arr);
char		**oneToDouble(char *str, int len, int width);
void		fill_map(char **array_2d, t_map *map);
void		fill_t_td(t_map *map, int i, int j);
// utils

int			get_length(char **arr);
int			get_height(char **arr);
void		draw(t_map *map, t_mlx *data);
int			close_window(int keycode, void *param);

// init
t_map		*init_map(int argc, char **argv);
t_td		*init_point(void);
t_mlx		*init_mlx(t_mlx *mlx);
void		init_win(t_mlx *mlx, t_map *map);

// free
void		free_str(char **ptr);
void		free_t_map(t_map *map);
void		free_td(t_td *td);
void		free_mlx(t_mlx *mlx);

// debug
void		print_t_map(t_map *map);
void		print_t_mlx(t_mlx *data);

#endif