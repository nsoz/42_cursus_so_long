/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:40:43 by muoz              #+#    #+#             */
/*   Updated: 2024/03/06 12:16:41 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_data
{
	char	**map;
	char	**map_copy;
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	void	*c_front;
	void	*zero;
	void	*colectable;
	void	*one;
	void	*exit;
	int		len;
	int		high;
	int		playerx;
	int		playery;
	int		colec_count;
}	t_data;

void	ft_error_massage(int flag);
void	ft_processing(char *str);
void	ft_check_map_design(char **map_copy);
void	ft_check_element(char **map_holder, int colectable);
void	ft_mlx_processes(t_data *info);
int		ft_find(char **map_copy, char flag);
int		ft_count(char **map_copy, char c);
void	ft_map_to_screen(t_data *info, int i, int j);
int		ft_press_w(t_data *info, char **map);
int		ft_press_s(t_data *info, char **map);
int		ft_press_a(t_data *info, char **map);
int		ft_press_d(t_data *info, char **map);
void	ft_print_step(void);
#endif