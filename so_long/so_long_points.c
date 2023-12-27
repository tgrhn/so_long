/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:10:24 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 17:10:25 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_map(t_list *data, char *str, int row_nbr)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	i = -1;
	j = 0;
	fd = open(str, O_RDONLY);
	data->map = malloc(sizeof(char *) * row_nbr);
	while (++i < row_nbr)
	{
		j = 0;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->map[i] = ft_strdup(line);
		while (j < ft_strlen(line))
		{
			data->map[i][j] = line[j];
			j++;
		}
		data->colon = j;
		free(line);
	}
	data->row = i;
}

void	ft_spawn_point(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->colon)
		{
			if (data->map[i][j] == 'P')
			{
				data->p_row = i;
				data->p_colon = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_end_point(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->colon)
		{
			if (data->map[i][j] == 'E')
			{
				data->exit_row = i;
				data->exit_colon = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_collectible_counter(t_list *data)
{
	int	i;
	int	j;
	int	collectibles;

	i = 0;
	j = 0;
	collectibles = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->colon)
		{
			if (data->map[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	data->collectibles = collectibles;
}
