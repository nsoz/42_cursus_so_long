/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:40:43 by muoz              #+#    #+#             */
/*   Updated: 2024/02/28 16:19:12 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

void	ft_error_massage(int flag);
void	ft_processing(char *str);
void	ft_check_map_design(char **map_copy);
void	ft_check_element(char **map_holder);
void	ft_free_all(char **arr);
#endif