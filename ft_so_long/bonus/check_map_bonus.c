/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:15:16 by sschanga          #+#    #+#             */
/*   Updated: 2022/11/05 21:47:54 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_wall(char **map, int x, int y)
{
	int	i;

	i = -1;
	while (map[0][++i] != 0)
		if (map[0][i] != '1')
			return (1);
	i = -1;
	while (map[y - 1][++i] != 0)
		if (map[y - 1][i] != '1')
			return (1);
	i = -1;
	while (map[++i] != NULL)
		if (map[i][0] != '1')
			return (1);
	i = -1;
	while (map[++i] != NULL)
		if (map[i][x - 1] != '1')
			return (1);
	return (0);
}

int	check_rectangular(t_init *game)
{
	int	i;

	i = 0;
	if (game->map.height * game->map.width != ft_strlen(game->map.map_witdh))
	{
		printf("Map is not rectangular\n");
		exit(0);
	}
	while (i < ft_strlen(game->map.map_witdh))
	{
		check_wall(game->map.map, game->map.width, game->map.height);
		i++;
	}
	return (0);
}

void	check_coins(t_init *game)
{
	int	i;

	i = 0;
	game->count.all_coins = 0;
	while (i < ft_strlen(game->map.map_witdh))
	{
		if (game->map.map_witdh[i] == 'C')
			game->count.all_coins++;
		i++;
	}
	if (game->count.all_coins == 0)
	{
		printf("Error\nNo Coins in the Map\n");
		exit(0);
	}
}

int	count_character(t_valid *check_valid)
{
	if (check_valid->count_exit == 0)
		printf("Error\nThere is no Exit\n");
	if (check_valid->count_player != 1)
		printf("Error\nThere is no Player\n");
	if (check_valid->count_enemy == 0)
		printf("Error\nThere is no Enemy\n");
	return (0);
}

int	check_character(t_init *game)
{
	int		i;
	t_valid	*check_valid;

	i = 0;
	check_valid->exit_code = 0;
	check_valid->count_player = 0;
	check_valid->count_exit = 0;
	check_valid->count_enemy = 0;
	while (++i < ft_strlen(game->map.map_witdh))
	{
		if (game->map.map_witdh[i] == 'E')
			check_valid->count_exit++;
		else if (game->map.map_witdh[i] == 'P')
			check_valid->count_player++;
		else if (game->map.map_witdh[i] == 'N')
			check_valid->count_enemy++;
		else if (game->map.map_witdh[i] != '0' && game->map.map_witdh[i] != '1'
			&& game->map.map_witdh[i] != 'C')
			check_valid->exit_code = 1;
	}
	count_character(check_valid);
	return (check_valid->exit_code);
}
