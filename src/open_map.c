/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:44:38 by alletond          #+#    #+#             */
/*   Updated: 2023/11/15 12:43:11 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_2d_char_array(char **arr)
{
	if (arr == NULL)
		return ;
	for (int i = 0; arr[i] != NULL; i++)
		ft_printf("%s\n", arr[i]);
}

char	*read_file_into_str(int fd)
{
	char	*line;
	char	*temp;
	char	*file_content;

	file_content = ft_strdup("");
	while ((line = get_next_line(fd)) != NULL)
	{
		temp = ft_strjoin(file_content, line);
		free(file_content);
		free(line);
		file_content = temp;
	}
	return (file_content);
}

char	*openfile(int argc, char **argv)
{
	int		fd;
	char	*file_content;

	if (argc != 2)
	{
		ft_printf("Usage: %s filename\n", argv[0]);
		return (NULL);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		return (NULL);
	}
	file_content = read_file_into_str(fd);
	close(fd);
	return (file_content);
}

char	**oneToDouble(char *str, int len, int width)
{
	char **strstr;
	int i = 0;
	int j = 0;
	int k = 0;

	strstr = malloc(sizeof(char *) * len);
	while (i < len)
	{
		strstr[i] = malloc(sizeof(char) * width + 1);
		i++;
	}
	i = 0;
	while (i != len)
	{
		while (j <= width)
		{
			strstr[i][j] = str[k];
			k++;
			j++;
		}
		j = 0;
		i++;
	}
	return (strstr);
}