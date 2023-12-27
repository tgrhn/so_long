/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_trial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:02:05 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/24 17:02:07 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_fake(t_list *data)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	data->fake_map = malloc(sizeof(char *) * data->row);
	while (++i < data->row)
	{
		j = 0;
		data->fake_map[i] = ft_strdup(data->map[i]);
		while (j < data->colon)
		{
			data->fake_map[i][j] = data->map[i][j];
			j++;
		}
	}
}

void	ft_flood(t_list *data, int x, int y)
{
	data->fake_map[x][y] = '*';
	if (data->fake_map[x - 1][y] != '1' && data->fake_map[x - 1][y] != '*'
			&& data->fake_map[x - 1][y] != 'E')
		ft_flood(data, x - 1, y);
	if (data->fake_map[x + 1][y] != '1' && data->fake_map[x + 1][y] != '*'
			&& data->fake_map[x + 1][y] != 'E')
		ft_flood(data, x + 1, y);
	if (data->fake_map[x][y - 1] != '1' && data->fake_map[x][y - 1] != '*'
			&& data->fake_map[x][y - 1] != 'E')
		ft_flood(data, x, y - 1);
	if (data->fake_map[x][y + 1] != '1' && data->fake_map[x][y + 1] != '*'
			&& data->fake_map[x][y + 1] != 'E')
		ft_flood(data, x, y + 1);
}

void	ft_finish(t_list *data, int x, int y)
{
	data->fake_map[x][y] = '.';
	if (data->fake_map[x - 1][y] != 1 && data->fake_map[x - 1][y] != '.'
			&& (data->fake_map[x - 1][y] == '*'
				|| data->fake_map[x - 1][y] == 'E'))
		ft_finish(data, x - 1, y);
	if (data->fake_map[x + 1][y] != 1 && data->fake_map[x + 1][y] != '.'
			&& (data->fake_map[x + 1][y] == '*'
				|| data->fake_map[x + 1][y] == 'E'))
		ft_finish(data, x + 1, y);
	if (data->fake_map[x][y - 1] != 1 && data->fake_map[x][y - 1] != '.'
			&& (data->fake_map[x][y - 1] == '*'
				|| data->fake_map[x][y - 1] == 'E'))
		ft_finish(data, x, y - 1);
	if (data->fake_map[x][y + 1] != 1 && data->fake_map[x][y + 1] != '.'
			&& (data->fake_map[x][y + 1] == '*'
				|| data->fake_map[x][y + 1] == 'E'))
		ft_finish(data, x, y + 1);
}

void	ft_finish_control(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_flood(data, data->p_row, data->p_colon);
	ft_finish(data, data->p_row, data->p_colon);
	while (i < data->row)
	{
		j = 0;
		while (j < data->colon)
		{
			if (data->fake_map[i][j] == 'C' || data->fake_map[i][j] == 'P'
					|| data->fake_map[i][j] == 'E')
				ft_error();
			j++;
		}
		i++;
	}
}
