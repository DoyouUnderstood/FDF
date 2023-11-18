/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:07:52 by alletond          #+#    #+#             */
/*   Updated: 2023/11/13 20:09:18 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mlx(t_mlx *mlx)
{
	if (mlx != NULL)
	{
		// Libérer l'image si elle a été créée
		if (mlx->mlx_img != NULL)
			mlx_destroy_image(mlx->mlx_ptr, mlx->mlx_img);
		// Libérer la fenêtre si elle a été créée
		if (mlx->mlx_win != NULL)
			mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		// Libération de la structure mlx elle-même
		free(mlx);
	}
}

void	free_td(t_td *td)
{
	free(td);
}

void	free_t_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

void	free_str(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}
