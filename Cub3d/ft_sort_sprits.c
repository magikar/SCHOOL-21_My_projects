/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_sprits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:31:25 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 15:17:47 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sort_order(t_pair *orders, int amount)
{
	int		i;
	int		j;
	t_pair	tmp;

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].dist > orders[j + 1].dist)
			{
				tmp.dist = orders[j].dist;
				tmp.order = orders[j].order;
				orders[j].dist = orders[j + 1].dist;
				orders[j].order = orders[j + 1].order;
				orders[j + 1].dist = tmp.dist;
				orders[j + 1].order = tmp.order;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_sprites(t_vars *vars, int *order, double *dist, int amount)
{
	int		i;
	t_pair	*sprites;

	i = 0;
	sprites = (t_pair *)malloc(sizeof(t_pair) * amount);
	if (!sprites)
		ft_exit_error(vars, "ERROR: FAIL MALLO! WTF?!?!");
	while (i < amount)
	{
		sprites[i].dist = dist[i];
		sprites[i].order = order[i];
		i++;
	}
	i = 0;
	ft_sort_order(sprites, amount);
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].dist;
		order[i] = sprites[amount - i - 1].order;
		i++;
	}
	free(sprites);
}
