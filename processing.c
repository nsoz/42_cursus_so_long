/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:47:36 by muoz              #+#    #+#             */
/*   Updated: 2024/03/06 02:25:59 by muoz             ###   ########.fr       */
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
	char	*ret;
	int		fd;
	int		row;

	row = 0;
	fd = open(str, O_RDONLY);
	ret = get_next_line(fd);
	if (fd == -1)
		ft_error_massage(3);
	while (ret != NULL)
	{
		row++;
		free(ret);
		ret = get_next_line(fd);
	}
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
		if ((ft_strchr(all_of_fd[lay], '\n')
				&& len_of_lay != ft_strlen(all_of_fd[lay]))
			|| (!ft_strchr(all_of_fd[lay], '\n')
				&& len_of_lay != ft_strlen(all_of_fd[lay]) + 1))
			ft_error_massage(4);
		lay++;
		all_of_fd[lay] = get_next_line(fd);
	}
	return (all_of_fd);
}

void	ft_processing(char *str)
{
	t_data	info;

	info.high = ft_row_cal(str) - 1;
	info.map = ft_read(str);
	info.map_copy = ft_get_copy(info.map);
	ft_check_map_design(info.map_copy);
	info.len = ft_strlen(info.map[0]) - 1;
	info.playerx = ft_find(info.map, 'x');
	info.playery = ft_find(info.map, 'y');
	info.colec_count = ft_count(info.map, 'C');
	ft_mlx_processes(&info);
}
