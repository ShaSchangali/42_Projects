/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:44:30 by sschanga          #+#    #+#             */
/*   Updated: 2022/11/06 00:25:37 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_enemy_next_pos(t_init *game, int i)
{
	int		next_pos;
	char	*map;

	map = game->map.map_witdh;
	next_pos = rand() % 4;
	if (next_pos == 0)
		next_pos = i - 1;
	else if (next_pos == 1)
		next_pos = i + 1;
	else if (next_pos == 2)
		next_pos = i - game->map.width;
	else if (next_pos == 3)
		next_pos = i + game->map.width;
	else
		printf("rand(): %d\n", rand());
	if (map[next_pos] == 'n')
		next_pos = rand() % 4;
	if (next_pos < 0 || next_pos >= ft_strlen(map) || map[next_pos] == 'E'
		|| map[next_pos] == 'C' || map[next_pos] == 'N' || map[next_pos] == '1')
		return (-1);
	return (next_pos);
}

int	set_enemy_next_pos(t_init *game, int i)
{
	int	next_pos;

	next_pos = get_enemy_next_pos(game, i);
	if (next_pos != -1)
	{
		if (game->map.map_witdh[next_pos] == 'P')
			key_press_esc(game);
		if (game->map.map_copy[next_pos] != 'C')
			game->map.map_witdh[i] = '0';
		else
			game->map.map_witdh[i] = 'C';
		game->map.map_witdh[next_pos] = 'n';
	}
	return (0);
}

int	change_enemy_char_to_upper_n(t_init *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->map.map_witdh))
		if (game->map.map_witdh[i] == 'n')
			game->map.map_witdh[i] = 'N';
	return (0);
}

int	enemy_patrol(t_init *game)
{
	int			i;
	static int	iter = 0;

	iter++;
	if (iter % 2000 != 0)
		return (1);
	i = 0;
	while (i++ < ft_strlen(game->map.map_witdh))
	{
		if (game->map.map_witdh[i] == 'N')
			set_enemy_next_pos(game, i);
	}
	change_enemy_char_to_upper_n(game);
	my_mlx_images_loader(game);
	return (0);
}
