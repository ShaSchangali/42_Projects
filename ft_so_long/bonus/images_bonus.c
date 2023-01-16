/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:49:55 by sschanga          #+#    #+#             */
/*   Updated: 2022/11/06 02:25:40 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_img	my_mlx_file_to_image(void *mlx)
{
	int		width;
	int		height;
	t_img	img;

	img.grass = mlx_xpm_file_to_image(mlx, "images/grass.xpm", &width, &height);
	img.brick = mlx_xpm_file_to_image(mlx, "images/brick.xpm", &width, &height);
	img.coin = mlx_xpm_file_to_image(mlx, "images/coin.xpm", &width, &height);
	img.player[0] = mlx_xpm_file_to_image(mlx, "images/pl1.xpm",
			&width, &height);
	img.player[1] = mlx_xpm_file_to_image(mlx, "images/pl2.xpm",
			&width, &height);
	img.door = mlx_xpm_file_to_image(mlx, "images/door.xpm", &width, &height);
	img.npc[0] = mlx_xpm_file_to_image(mlx, "images/npc1.xpm",
			&width, &height);
	img.npc[1] = mlx_xpm_file_to_image(mlx, "images/npc2.xpm",
			&width, &height);
	return (img);
}

void	put_anim_sprite(t_init *game, int width, int height)
{
	int	i;
	int	j;

	game->img.sprite_index[0]++;
	game->img.sprite_index[1]++;
	if (game->img.sprite_index[0] % 10 > 5)
		i = 1;
	else if (game->img.sprite_index[0] % 10 <= 5)
		i = 0;
	if (game->img.sprite_index[1] % 10 > 5)
		j = 1;
	else if (game->img.sprite_index[1] % 10 <= 5)
		j = 0;
	if (game->map.map_witdh[height * game->map.width + width] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.player[i],
			width * 64, height * 64);
	else if (game->map.map_witdh[height * game->map.width + width] == 'N')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.npc[j],
			width * 64, height * 64);
}

void	my_mlx_image_to_window(t_init *game, int width, int height)
{
	if (game->map.map_witdh[height * game->map.width + width] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.brick,
			width * 64, height * 64);
	else if (game->map.map_witdh[height * game->map.width + width] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.coin,
			width * 64, height * 64);
	else if (game->map.map_witdh[height * game->map.width + width] == 'P'
		|| game->map.map_witdh[height * game->map.width + width] == 'N')
		put_anim_sprite(game, width, height);
	else if (game->map.map_witdh[height * game->map.width + width] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.door,
			width * 64, height * 64);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.grass,
			width * 64, height * 64);
}

void	my_mlx_images_loader(t_init *game)
{
	int		width;
	int		height;
	char	*buff;

	height = 0;
	while (height < game->map.height)
	{
		width = 0;
		while (width < game->map.width)
		{
			my_mlx_image_to_window(game, width, height);
			width++;
		}
		height++;
	}
	buff = ft_itoa(game->count.walk_cnt);
	mlx_string_put(game->mlx, game->mlx_win, 10, 250, 0x00FF0000,
		buff);
	free (buff);
}
