/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:15:01 by muoz              #+#    #+#             */
/*   Updated: 2024/03/06 00:57:37 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_border_line_next(char map_holder)
{
	if (map_holder == '1')
		return (0);
	else
		return (1);
}

void	ft_check_border_line(char **map_holder)
{
	size_t	i;
	size_t	a;

	a = -1;
	i = -1;
	while (map_holder[++i] != NULL)
	{
		if (i == 0 || map_holder[i + 1] == NULL)
		{
			while (map_holder[i][++a] != '\0')
				if (map_holder[i][a] != '1' && map_holder[i][a] != '\n' )
					break ;
			if (map_holder[i][a] != '\0')
				ft_error_massage(9);
		}
		else
			if ((ft_strchr(map_holder[i], '\n'))
				&& (ft_check_border_line_next(map_holder[i][0])
				|| ft_check_border_line_next
				(map_holder[i][ft_strlen(map_holder[i]) - 2])))
				ft_error_massage(9);
		a = -1;
	}
}

void	ft_check_stranger_things(char **map_holder)
{
	int	i;
	int	c;

	i = -1;
	c = -1;
	while (map_holder[++i] != NULL)
	{
		while (map_holder[i][++c] != '\0')
		{
			if (map_holder[i][c] != '0'
			&& map_holder[i][c] != '1'
			&& map_holder[i][c] != '\n'
			&& map_holder[i][c] != 'E'
			&& map_holder[i][c] != 'C'
			&& map_holder[i][c] != 'P')
			{
				ft_free_all(map_holder);
				ft_error_massage(10);
			}
		}
		c = -1;
	}
	ft_check_border_line(map_holder);
}

void	ft_error_sender(int ext, int colecteable, int player)
{
	if (ext == 0 || ext > 1)
		ft_error_massage(6);
	else if (player == 0 || player > 1)
		ft_error_massage(7);
	else if (colecteable == 0)
		ft_error_massage(8);
}

void	ft_check_element(char **map_holder, int colectable)
{
	int	i;
	int	j;
	int	ext;
	int	player;

	player = 0;
	ext = 0;
	i = -1;
	j = -1;
	ft_check_stranger_things(map_holder);
	while (map_holder[++i] != NULL)
	{
		while (map_holder[i][++j] != '\0')
		{
			if (map_holder[i][j] == 'E')
				ext += 1;
			if (map_holder[i][j] == 'P')
				player += 1;
			if (map_holder[i][j] == 'C')
				colectable = 1;
		}
		j = -1;
	}
	ft_error_sender(ext, colectable, player);
}
