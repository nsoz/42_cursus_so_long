/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:12:16 by muoz              #+#    #+#             */
/*   Updated: 2024/03/06 02:20:56 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_textures(t_data *info)
{
	int	high;
	int	len;

	high = 64;
	len = 64;
	info->c_front = mlx_xpm_file_to_image(info->mlx_ptr,
			"./textures/c_front.xpm", &len, &high);
	info->zero = mlx_xpm_file_to_image(info->mlx_ptr,
			"./textures/zero.xpm", &len, &high);
	info->one = mlx_xpm_file_to_image(info->mlx_ptr,
			"./textures/one.xpm", &len, &high);
	info->colectable = mlx_xpm_file_to_image(info->mlx_ptr,
			"./textures/colectable.xpm", &len, &high);
	info->exit = mlx_xpm_file_to_image(info->mlx_ptr,
			"./textures/exit.xpm", &len, &high);
	if (!info->c_front || !info->zero
		|| !info->one || !info->colectable || !info->exit)
		ft_error_massage(12);
}

void	ft_map_to_screen(t_data *info, int i, int j)
{
	mlx_clear_window(info->mlx_ptr, info->mlx_win_ptr);
	printf("%d %d\n", info->high, info->len);
	while (++i < info->high)
	{
		j = -1;
		while (++j < info->len)
		{
			mlx_put_image_to_window(info->mlx_ptr,
				info->mlx_win_ptr, info->zero, (j * 64), (i * 64));
			if (info->map[i][j] == 'P')
				mlx_put_image_to_window(info->mlx_ptr,
					info->mlx_win_ptr, info->c_front, (j * 64), (i * 64));
			if (info->map[i][j] == '1')
				mlx_put_image_to_window(info->mlx_ptr,
					info->mlx_win_ptr, info->one, (j * 64), (i * 64));
			if (info->map[i][j] == 'C')
				mlx_put_image_to_window(info->mlx_ptr,
					info->mlx_win_ptr, info->colectable, (j * 64), (i * 64));
			if (info->map[i][j] == 'E')
				mlx_put_image_to_window(info->mlx_ptr,
					info->mlx_win_ptr, info->exit, (j * 64), (i * 64));
		}
	}
}

int	ft_press_esc(t_data *info)
{
	mlx_destroy_image(info->mlx_ptr, info->exit);
	mlx_destroy_image(info->mlx_ptr, info->zero);
	mlx_destroy_image(info->mlx_ptr, info->one);
	mlx_destroy_image(info->mlx_ptr, info->colectable);
	mlx_destroy_image(info->mlx_ptr, info->c_front);
	mlx_destroy_window(info->mlx_ptr, info->mlx_win_ptr);
	exit(0);
}

int	ft_keycode(int code, t_data *info)
{
	if (code == 13)
		ft_press_w(info, info->map);
	else if (code == 1)
		ft_press_s(info, info->map);
	else if (code == 2)
		ft_press_d(info, info->map);
	else if (code == 0)
		ft_press_a(info, info->map);
	else if (code == 53)
		ft_press_esc(info);
	return (0);
}

void	ft_mlx_processes(t_data *info)
{
	info->mlx_ptr = mlx_init();
	info->mlx_win_ptr = mlx_new_window(info->mlx_ptr,
			(info->len * 64), (info->high * 64), "so_long");
	ft_get_textures(info);
	ft_map_to_screen(info, -1, -1);
	mlx_hook(info->mlx_win_ptr, 2, 0, ft_keycode, info);
	mlx_hook(info->mlx_win_ptr, 17, 0, ft_press_esc, info);
	mlx_loop(info->mlx_ptr);
}
