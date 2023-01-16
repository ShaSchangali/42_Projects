/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:16:19 by sschanga          #+#    #+#             */
/*   Updated: 2022/11/05 23:12:33 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress_settings(int key, t_init *game)
{
	if (key == 13)
		key_press_w(game);
	else if (key == 1)
		key_press_s(game);
	else if (key == 0)
		key_press_a(game);
	else if (key == 2)
		key_press_d(game);
	else if (key == 53)
		key_press_esc(game);
	return (0);
}

int	map_load_settings(t_init *game)
{
	int		i;
	int		j;
	t_valid	*check_valid;

	if (check_wall(game->map.map, game->map.width, game->map.height) != 0)
	{
		printf("Error\nWalls are not Valid\n");
		exit(0);
	}
	if (valid_path(check_valid, game->map.map, i, j) != 0)
	{
		printf("Error\nPath is not Valid\n");
		exit(0);
	}
	check_rectangular(game);
	check_coins(game);
	if (check_character(game))
		return (1);
	return (0);
}

int	game_load_settings(t_init *game, char *file)
{	
	game->count.col_coins = 0;
	game->count.all_coins = 0;
	game->img.sprite_index[0] = 0;
	game->img.sprite_index[1] = 1;
	game->mlx = mlx_init();
	game->img = my_mlx_file_to_image(game->mlx);
	if (read_map(game, file))
		return (1);
	game->map.map_copy = ft_strdup_(game->map.map_witdh);
	parse_map_2d(game);
	print_map(game->map.map);
	if (map_load_settings(game))
		return (1);
	game->mlx_win = mlx_new_window(game->mlx, game->map.width * 64,
			game->map.height * 64, "Get rich or die trying");
	return (0);
}

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free(map);
}

int	main(int ac, char *av[])
{
	t_init	game;

	game.map.map = NULL;
	if (game_load_settings(&game, av[1]))
	{
		write (2, "Error\nBad Map!\n", 13);
		if (game.map.map)
			free_map(game.map.map);
		return (1);
	}
	mlx_hook(game.mlx_win, 2, 0, &keypress_settings, &game);
	mlx_loop_hook (game.mlx, &enemy_patrol, &game);
	mlx_hook(game.mlx_win, 17, 1L << 3, &quit_game, &game);
	mlx_loop(game.mlx);
	printf("%d\n", game.count.all_coins);
	return (0);
}
