/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 03:19:20 by muoz              #+#    #+#             */
/*   Updated: 2024/03/06 14:42:10 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_find(char **map_copy, char flag)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map_copy[y][x])
	{
		while (map_copy[y][x] != '\0')
		{
			if (map_copy[y][x] == 'P')
				break ;
			x++;
		}
		if (map_copy[y][x] == 'P')
			break ;
		x = 0;
		y++;
	}
	if (flag == 'x')
		return (x);
	else
		return (y);
}

void	ft_flood_fill_next(char **map_holder, int x, int y)
{
	map_holder[y][x] = '.';
	if (map_holder[y][x + 1] && map_holder[y][x + 1] != '1'
			&& map_holder[y][x + 1] != '.')
		ft_flood_fill_next(map_holder, (x + 1), y);
	if (map_holder[y + 1][x] && map_holder[y + 1][x] != '1'
			&& map_holder[y + 1][x] != '.')
		ft_flood_fill_next(map_holder, x, (y + 1));
	if (map_holder[y][x - 1] && map_holder[y][x - 1] != '1'
			&& map_holder[y][x - 1] != '.')
		ft_flood_fill_next(map_holder, (x - 1), y);
	if (map_holder[y - 1][x] && map_holder[y - 1][x] != '1'
			&& map_holder[y - 1][x] != '.')
		ft_flood_fill_next(map_holder, x, (y - 1));
}

void	ft_flood_fill(char **map_holder, int x, int y)
{
	map_holder[y][x] = '*';
	if (map_holder[y][x + 1] && map_holder[y][x + 1] != '1'
		&& map_holder[y][x + 1] != '*' && map_holder[y][x + 1] != 'E')
		ft_flood_fill(map_holder, (x + 1), y);
	if (map_holder[y + 1][x] && map_holder[y + 1][x] != '1'
		&& map_holder[y + 1][x] != '*' && map_holder[y + 1][x] != 'E')
		ft_flood_fill(map_holder, x, (y + 1));
	if (map_holder[y][x - 1] && map_holder[y][x - 1] != '1'
		&& map_holder[y][x - 1] != '*' && map_holder[y][x - 1] != 'E')
		ft_flood_fill(map_holder, (x - 1), y);
	if (map_holder[y - 1][x] && map_holder[y - 1][x] != '1'
		&& map_holder[y - 1][x] != '*' && map_holder[y - 1][x] != 'E')
		ft_flood_fill(map_holder, x, (y - 1));
}

void	ft_is_able_to_play(char **map_holder)
{
	int	i;

	i = -1;
	while (map_holder[++i] != NULL)
	{
		if (ft_strchr(map_holder[i], 'P') || ft_strchr(map_holder[i], 'E')
			|| ft_strchr(map_holder[i], 'C'))
			ft_error_massage(11);
	}
}

void	ft_check_map_design(char **map_copy)
{
	int	x;
	int	y;

	x = ft_find(map_copy, 'x');
	y = ft_find(map_copy, 'y');
	if (!map_copy)
		ft_error_massage(5);
	ft_check_element(map_copy, 0);
	ft_flood_fill(map_copy, x, y);
	if (ft_count(map_copy, 'C') != 0)
		ft_error_massage(11);
	ft_flood_fill_next(map_copy, x, y);
	ft_is_able_to_play(map_copy);
}
