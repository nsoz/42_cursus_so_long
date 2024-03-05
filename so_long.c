/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:25:21 by muoz              #+#    #+#             */
/*   Updated: 2024/03/06 02:21:41 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_massage(int flag)
{
	if (flag == 1)
		write(1, "Missing argument", 16);
	else if (flag == 2)
		write(1, "Wrong extension", 15);
	else if (flag == 3)
		write(1, "File descriptor failed", 22);
	else if (flag == 4)
		write(1, "Map is not equal len", 20);
	else if (flag == 5)
		write(1, "Map could not be copied", 23);
	else if (flag == 6)
		write(1, "The map does not contain exit or it has more than one", 53);
	else if (flag == 7)
		write(1, "The map does not contain player or it has more than one", 55);
	else if (flag == 8)
		write(1, "The map does not contain colecteable", 36);
	else if (flag == 9)
		write(1, "incomplete map", 14);
	else if (flag == 10)
		write(1, "map has alien character", 23);
	else if (flag == 11)
		write(1, "game isn't able to play", 23);
	else if (flag == 12)
		write(1, "texture file couldn't find", 27);
	exit(1);
}

char	*ft_reach_to_extension(char *str)
{
	char	*new_str;

	new_str = ft_strrchr(str, '.');
	new_str += ft_strlen(new_str) - 4;
	return (new_str);
}

int	ft_is_dot_ber(char *str)
{
	char	*ext_str;
	size_t	len;

	len = ft_strlen(str);
	if (len <= 4)
		ft_error_massage(2);
	if (!ft_strncmp(str + ft_strlen(str) - 5, "/.ber", 5))
		ft_error_massage(2);
	if ((len == 5 && !ft_strncmp(str, "..ber", 5))
		|| (len > 5
			&& !ft_strncmp(str + ft_strlen(str) - 6, "/..ber", 6)))
		ft_error_massage(2);
	ext_str = ft_reach_to_extension(str);
	return (ft_strncmp(ext_str, ".ber", 4));
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (av[1][0] != '\0')
		{
			if (!(ft_is_dot_ber(av[1])))
				ft_processing(av[1]);
			else
				ft_error_massage(2);
		}
		else
			write(1, "wrong argument", 14);
	}
	else
		ft_error_massage(1);
	return (0);
}
