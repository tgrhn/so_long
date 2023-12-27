/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:10:41 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 17:10:42 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_list *data)
{
	ft_mlx_init(data);
	ft_wall_backg_init(data);
	ft_collectible_counter(data);
	ft_player_coin_exit_init(data);
}

void	ft_counter_control(t_list *data)
{
	if (data->end_counter > 1 || data->start_counter > 1
		|| data->start_counter == 0
		|| data->end_counter == 0 || data->collectibles < 1)
		ft_error();
}

void	ft_control_map(int row_nbr, char *str, t_list *data)
{
	int		fd;
	char	*c;
	int		i;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error();
	i = 0;
	fd = open(str, O_RDONLY);
	c = get_next_line(fd);
	ft_map_control(c);
	free(c);
	ft_find_row_column_equality(str, 1);
	while (i < row_nbr - 2)
	{
		c = get_next_line(fd);
		ft_map_control_lines(c, data);
		free(c);
		i++;
	}
	c = get_next_line(fd);
	ft_map_control(c);
	free(c);
}

int	main(int argc, char **argv)
{
	char	*c;
	int		row_nbr;
	int		i;
	t_list	*data;

	data = malloc(sizeof(t_list));
	i = 0;
	if (argc > 2 || argv[1] == NULL || argc == 1)
		ft_error();
	row_nbr = ft_find_row(argv[1]);
	data->start_counter = 0;
	data->end_counter = 0;
	data->collectibles = 0;
	ft_control_map(row_nbr, argv[1], data);
	ft_counter_control(data);
	ft_fill_map(data, argv[1], row_nbr);
	ft_init(data);
	mlx_hook(data->mlxwin, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->mlxwin, 17, 1L << 2, ft_press_esc, data);
	mlx_loop(data->mlx);
	return (0);
}
