/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_initialize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:10:49 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 17:10:50 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_wall_backg_init(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlxwin,
					data->wall, j * 64, i * 64);
			else
				mlx_put_image_to_window(data->mlx, data->mlxwin,
					data->backg, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	ft_player_coin_exit_init(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlxwin,
					data->exit, j * 64, i * 64);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlxwin,
					data->coin, j * 64, i * 64);
			else if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlxwin,
					data->player, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	ft_mlx_init(t_list *data)
{
	int	i;

	i = 64;
	data->mlx = mlx_init();
	data->step = 0;
	ft_spawn_point(data);
	ft_end_point(data);
	ft_fill_fake(data);
	ft_finish_control(data);
	data->mlxwin = mlx_new_window(data->mlx, data->colon * 64,
			data->row * 64, "The Batman");
	data->backg = mlx_xpm_file_to_image(data->mlx,
			"textures/background.xpm", &i, &i);
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"textures/wall.xpm", &i, &i);
	data->player = mlx_xpm_file_to_image(data->mlx,
			"textures/character.xpm", &i, &i);
	data->exit = mlx_xpm_file_to_image(data->mlx,
			"textures/exit.xpm", &i, &i);
	data->coin = mlx_xpm_file_to_image(data->mlx,
			"textures/collectables.xpm", &i, &i);
}
