/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:47:36 by muoz              #+#    #+#             */
/*   Updated: 2024/02/28 17:49:45 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i] != NULL)
		free(arr[i]);
	free(arr);
}

int	ft_row_cal(char *str)
{
	int	fd;
	int	row;

	row = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error_massage(3);
	while (get_next_line(fd) != NULL)
		row++;
	close (fd);
	return (row + 1);
}

char	**ft_get_copy(char **src)
{
	char	**dest;
	int		layer;
	int		copy_lay;

	layer = 0;
	copy_lay = 0;
	while (src[layer] != NULL)
		layer++;
	dest = malloc((layer + 1) * sizeof(char *));
	while (copy_lay < layer)
	{
		dest[copy_lay] = ft_strdup(src[copy_lay]);
		copy_lay++;
	}
	dest[copy_lay] = NULL;
	return (dest);
}

char	**ft_read(char *str)
{
	char	**all_of_fd;
	int		fd;
	int		lay;
	size_t	len_of_lay;

	lay = 0;
	all_of_fd = malloc(ft_row_cal(str) * sizeof(char *));
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error_massage(3);
	all_of_fd[lay] = get_next_line(fd);
	len_of_lay = ft_strlen(all_of_fd[lay]);
	while ((all_of_fd[lay] != NULL))
	{
		if (ft_strchr(all_of_fd[lay], '\n')
			&& len_of_lay != ft_strlen(all_of_fd[lay]))
		{
			ft_free_all(all_of_fd);
			ft_error_massage(4);
		}
		lay++;
		all_of_fd[lay] = get_next_line(fd);
	}
	return (all_of_fd);
}

void	ft_processing(char *str) 
{
	char	**map;
	char	**map_copy;

	map = ft_read(str);
	map_copy = ft_get_copy(map);
	ft_check_map_design(map_copy);
	ft_free_all(map);
	ft_free_all(map_copy);
}
