/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_counters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:00 by tkarakad          #+#    #+#             */
/*   Updated: 2023/12/23 17:11:13 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

void	ft_collectible(t_list *data)
{
	if (data->collectibles == 0)
	{
		write(1, "You have finished the game!\n", 29);
		exit(0);
	}
}

void	ft_step_counter(t_list *data)
{
	static int	step = 0;

	step++;
	data->step = step;
	write(1, "Step Counter : ", 16);
	ft_putnbr(data->step);
	write(1, "\n", 1);
}
