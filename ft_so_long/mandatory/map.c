/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:09:48 by sschanga          #+#    #+#             */
/*   Updated: 2022/11/05 20:52:23 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(t_init *game, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		return (1);
	line = get_next_line(fd);
	game->map.height = 0;
	game->count.walk_cnt = 0;
	game->map.width = ft_strlen(line) - 1;
	game->map.map_witdh = ft_strdup_(line);
	free(line);
	line = "";
	while (line)
	{
		game->map.height++;
		line = get_next_line(fd);
		if (line != NULL)
			game->map.map_witdh = ft_strjoin_(game->map.map_witdh, line);
	}
	free(line);
	close(fd);
	return (0);
}

void	parse_map_2d(t_init *game)
{
	int		i;
	int		j;
	char	**map;

	game->map.map = malloc(sizeof(char *) * (game->map.height + 1));
	map = game->map.map;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		map[i] = malloc(game->map.width + 1);
		while (j < game->map.width)
		{
			if (map[i] == NULL)
			{
				printf("Error\nMap Parsing Error\n");
				exit(0);
			}
			map[i][j] = game->map.map_witdh[j + (i * game->map.width)];
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
}

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	quit_game(t_init *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	printf("Error\n You Quit the game.\n");
	exit(0);
}
