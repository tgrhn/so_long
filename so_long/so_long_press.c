/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_press.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:09:39 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 17:09:41 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_press_left(t_list *data)
{
	int	collectibles;

	collectibles = data->collectibles;
	if (data->map[data->p_row][data->p_colon - 1] != '1')
	{
		if (data->map[data->p_row][data->p_colon - 1] != 'E')
		{
			ft_step_counter(data);
			if (data->map[data->p_row][data->p_colon - 1] == 'C')
				collectibles -= 1;
			data->map[data->p_row][data->p_colon - 1] = 'P';
			data->map[data->p_row][data->p_colon] = '0';
			ft_spawn_point(data);
			ft_wall_backg_init(data);
			ft_player_coin_exit_init(data);
		}
		else
			ft_collectible(data);
	}
	data->collectibles = collectibles;
}

void	ft_press_right(t_list *data)
{
	int	collectibles;

	collectibles = data->collectibles;
	if (data->map[data->p_row][data->p_colon + 1] != '1')
	{
		if (data->map[data->p_row][data->p_colon + 1] != 'E')
		{
			ft_step_counter(data);
			if (data->map[data->p_row][data->p_colon + 1] == 'C')
				collectibles -= 1;
			data->map[data->p_row][data->p_colon + 1] = 'P';
			data->map[data->p_row][data->p_colon] = '0';
			ft_spawn_point(data);
			ft_wall_backg_init(data);
			ft_player_coin_exit_init(data);
		}
		else
			ft_collectible(data);
	}
	data->collectibles = collectibles;
}

void	ft_press_up(t_list *data)
{
	int	collectibles;

	collectibles = data->collectibles;
	if (data->map[data->p_row - 1][data->p_colon] != '1')
	{
		if (data->map[data->p_row - 1][data->p_colon] != 'E')
		{
			ft_step_counter(data);
			if (data->map[data->p_row - 1][data->p_colon] == 'C')
				collectibles -= 1;
			data->map[data->p_row - 1][data->p_colon] = 'P';
			data->map[data->p_row][data->p_colon] = '0';
			ft_spawn_point(data);
			ft_wall_backg_init(data);
			ft_player_coin_exit_init(data);
		}
		else
			ft_collectible(data);
	}
	data->collectibles = collectibles;
}

void	ft_press_down(t_list *data)
{
	int	collectibles;

	collectibles = data->collectibles;
	if (data->map[data->p_row + 1][data->p_colon] != '1')
	{
		ft_step_counter(data);
		if (data->map[data->p_row + 1][data->p_colon] != 'E')
		{
			if (data->map[data->p_row + 1][data->p_colon] == 'C')
				collectibles = collectibles - 1;
			data->map[data->p_row + 1][data->p_colon] = 'P';
			data->map[data->p_row][data->p_colon] = '0';
			ft_spawn_point(data);
			ft_wall_backg_init(data);
			ft_player_coin_exit_init(data);
		}
		else
			ft_collectible(data);
	}
	data->collectibles = collectibles;
}

int	handle_keypress(int key, t_list *data)
{
	if (key == LEFT)
		ft_press_left(data);
	else if (key == RIGHT)
		ft_press_right(data);
	else if (key == UP)
		ft_press_up(data);
	else if (key == DOWN)
		ft_press_down(data);
	else if (key == ESC)
		ft_press_esc(data);
	return (0);
}
