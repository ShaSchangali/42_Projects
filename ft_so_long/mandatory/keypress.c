/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:07:21 by sschanga          #+#    #+#             */
/*   Updated: 2022/11/06 02:41:47 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_press_esc(t_init *game)
{
	game->count.walk_cnt++;
	printf("All Collectibles: %d\n", game->count.all_coins);
	printf("Your Collectibles: %d\n", game->count.col_coins);
	printf("%s %d%s\n", "FINSIH! You took", game->count.walk_cnt, "steps.");
	exit(0);
}

void	key_press_w(t_init *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->map.map_witdh))
		if (game->map.map_witdh[i] == 'P')
			break ;
	if (game->map.map_witdh[i - game->map.width] == 'C')
		game->count.col_coins++;
		game->map.map_copy[i - game->map.width] = '0';
	if (game->map.map_witdh[i - game->map.width] == 'E'
		&& game->count.all_coins == game->count.col_coins)
		key_press_esc(game);
	if (game->map.map_witdh[i - game->map.width] == 'N')
		key_press_esc(game);
	else if (game->map.map_witdh[i - game->map.width] != '1'
		&& game->map.map_witdh[i - game->map.width] != 'E')
	{
		game->map.map_witdh[i] = '0';
		game->map.map_witdh[i - game->map.width] = 'P';
		game->count.walk_cnt++;
		my_mlx_images_loader(game);
	}
}

void	key_press_s(t_init *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->map.map_witdh))
		if (game->map.map_witdh[i] == 'P')
			break ;
	if (game->map.map_witdh[i + game->map.width] == 'C')
	{
		game->count.col_coins++;
		game->map.map_copy[i + game->map.width] = '0';
	}
	if (game->map.map_witdh[i + game->map.width] == 'E'
		&& game->count.all_coins == game->count.col_coins)
		key_press_esc(game);
	if (game->map.map_witdh[i + game->map.width] == 'N')
		key_press_esc(game);
	else if (game->map.map_witdh[i + game->map.width] != '1'
		&& game->map.map_witdh[i + game->map.width] != 'E')
	{
		game->map.map_witdh[i] = '0';
		game->map.map_witdh[i + game->map.width] = 'P';
		game->count.walk_cnt++;
		my_mlx_images_loader(game);
	}
	printf("Movement: %d\n", game->count.walk_cnt);
}

void	key_press_a(t_init *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->map.map_witdh))
		if (game->map.map_witdh[i] == 'P')
			break ;
	if (game->map.map_witdh[i - 1] == 'C')
	{
		game->count.col_coins++;
		game->map.map_copy[i - 1] = '0';
	}
	if (game->map.map_witdh[i - 1] == 'E'
		&& game->count.all_coins == game->count.col_coins)
		key_press_esc(game);
	if (game->map.map_witdh[i - 1] == 'N')
		key_press_esc(game);
	else if (game->map.map_witdh[i - 1] != '1'
		&& game->map.map_witdh[i - 1] != 'E')
	{
		game->map.map_witdh[i] = '0';
		game->map.map_witdh[i - 1] = 'P';
		game->count.walk_cnt++;
		my_mlx_images_loader(game);
	}
	printf("Movement: %d\n", game->count.walk_cnt);
}

void	key_press_d(t_init *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->map.map_witdh))
		if (game->map.map_witdh[i] == 'P')
			break ;
	if (game->map.map_witdh[i + 1] == 'C')
	{
		game->count.col_coins++;
		game->map.map_copy[i + 1] = '0';
	}
	if (game->map.map_witdh[i + 1] == 'E'
		&& game->count.all_coins == game->count.col_coins)
		key_press_esc(game);
	if (game->map.map_witdh[i + 1] == 'N')
		key_press_esc(game);
	else if (game->map.map_witdh[i + 1] != '1'
		&& game->map.map_witdh[i + 1] != 'E')
	{
		game->map.map_witdh[i] = '0';
		game->map.map_witdh[i + 1] = 'P';
		game->count.walk_cnt++;
		my_mlx_images_loader(game);
	}
	printf("Movement: %d\n", game->count.walk_cnt);
}
