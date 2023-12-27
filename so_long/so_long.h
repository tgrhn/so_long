/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:14:01 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 17:14:02 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx/mlx.h"

# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	53

typedef struct s_list
{
	int		row;
	int		colon;
	char	**map;
	char	**fake_map;
	char	*str;
	int		p_colon;
	int		p_row;
	void	*mlx;
	void	*mlxwin;
	void	*wall;
	void	*exit;
	void	*coin;
	void	*joker;
	int		exit_row;
	int		exit_colon;
	void	*player;
	void	*backg;
	int		collectibles;
	int		step;
	int		start_counter;
	int		end_counter;
}	t_list;

char	*get_next_line(int fd);
int		ft_map_control(char *str);
int		ft_map_control_lines(char *str, t_list *data);
int		ft_map_control_rectangular(int row_nbr, char *str);
int		ft_find_row_column_equality(char *str, int i);
int		ft_find_row(char *str);
int		ft_strlen(char *str);
void	ft_error(void);
void	ft_spawn_point(t_list *data);
void	ft_fill_map(t_list *data, char *str, int row_nbr);
char	*ft_strdup(char *s1);
void	ft_end_point(t_list *data);
void	ft_collectible_counter(t_list *data);
int		handle_keypress(int keysym, t_list *data);
void	ft_wall_backg_init(t_list *data);
void	ft_player_coin_exit_init(t_list *data);
void	ft_press_left(t_list *data);
void	ft_mlx_init(t_list *data);
void	ft_collectible(t_list *data);
void	ft_step_counter(t_list *data);
int		ft_press_esc(t_list *data);
void	ft_press_down(t_list *data);
void	ft_press_up(t_list *data);
void	ft_press_right(t_list *data);
void	ft_init(t_list *data);
void	ft_wall_backg_init(t_list *data);
void	ft_player_coin_exit_init(t_list *data);
void	ft_finish_control(t_list *data);
void	ft_finish(t_list *data, int x, int y);
void	ft_flood(t_list *data, int x, int y);
void	ft_fill_fake(t_list *data);
#endif
