/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:56:45 by alletond          #+#    #+#             */
/*   Updated: 2023/11/13 20:09:04 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_length(char **arr)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (arr[0][i])
	{
		if (arr[0][i] >= '0' && arr[0][i] <= '9')
		{
			len++;
			while (arr[0][i] && arr[0][i] >= '0' && arr[0][i] <= '9')
				i++;
		}
		else
			i++;
	}
	return (len);
}

int	get_height(char **arr)
{
	int	height;

	height = 0;
	while (arr[height])
	{
		height++;
	}
	return (height);
}
