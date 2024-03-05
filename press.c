#include "so_long.h"

void	ft_print_step(void)
{
	static int	i = 0;

	i++;
	write(1, "step = ", 7);
	ft_putnbr_fd(i, 1);
	write(1, "\n", 1);
}

void	ft_finish(t_data *info)
{
	ft_print_step();
	write(1, "YOU WİN\n", 9);
	mlx_destroy_image(info->mlx_ptr, info->exit);
	mlx_destroy_image(info->mlx_ptr, info->zero);
	mlx_destroy_image(info->mlx_ptr, info->one);
	mlx_destroy_image(info->mlx_ptr, info->colectable);
	mlx_destroy_image(info->mlx_ptr, info->c_front);
	mlx_destroy_window(info->mlx_ptr, info->mlx_win_ptr);
	exit (0);
}

int	ft_press_w(t_data *info, char **map)
{
	info->colec_count = ft_count(info->map, 'C');
	if ((map[info->playery - 1][info->playerx] == 'E')
			&& (info->colec_count == 0))
		ft_finish(info);
	else if (map[info->playery - 1][info->playerx] != 'E')
	{
		if (map[info->playery - 1][info->playerx] != '1')
		{
			map[info->playery][info->playerx] = '0';
			map[info->playery - 1][info->playerx] = 'P';
			ft_print_step();
		}
		info->playerx = ft_find(info->map, 'x');
		info->playery = ft_find(info->map, 'y');
		ft_map_to_screen(info, -1, -1);
	}
	return (0);
}
int	ft_press_s(t_data *info, char **map)
{
	info->colec_count = ft_count(info->map, 'C');
	if ((map[info->playery + 1][info->playerx] == 'E')
			&& (info->colec_count == 0))
		ft_finish(info);
	else if (map[info->playery + 1][info->playerx] != 'E')
	{
		if (map[info->playery + 1][info->playerx] != '1')
		{
			map[info->playery][info->playerx] = '0';
			map[info->playery + 1][info->playerx] = 'P';
			ft_print_step();
		}
		info->playerx = ft_find(info->map, 'x');
		info->playery = ft_find(info->map, 'y');
		ft_map_to_screen(info, -1, -1);
	}
	return (0);
}
int	ft_press_a(t_data *info, char **map)
{
	info->colec_count = ft_count(info->map, 'C');
	if ((map[info->playery][info->playerx - 1] == 'E')
			&& (info->colec_count == 0))
		ft_finish(info);
	else if (map[info->playery][info->playerx - 1] != 'E')
	{
		if (map[info->playery][info->playerx - 1] != '1')
		{
			map[info->playery][info->playerx] = '0';
			map[info->playery][info->playerx - 1] = 'P';
			ft_print_step();
		}
		info->playerx = ft_find(info->map, 'x');
		info->playery = ft_find(info->map, 'y');
		ft_map_to_screen(info, -1, -1);
	}
	return (0);
}
int	ft_press_d(t_data *info, char **map)
{
	info->colec_count = ft_count(info->map, 'C');
	if ((map[info->playery][info->playerx + 1] == 'E')
			&& (info->colec_count == 0))
		ft_finish(info);
	else if (map[info->playery][info->playerx + 1] != 'E')
	{
		if (map[info->playery][info->playerx + 1] != '1')
		{
			map[info->playery][info->playerx] = '0';
			map[info->playery][info->playerx + 1] = 'P';
			ft_print_step();
		}
		info->playerx = ft_find(info->map, 'x');
		info->playery = ft_find(info->map, 'y');
		ft_map_to_screen(info, -1, -1);
	}
	return (0);
}