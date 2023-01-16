/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:16:24 by sschanga          #+#    #+#             */
/*   Updated: 2022/11/05 21:47:21 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	char	**map;
	char	*map_copy;
	char	*map_witdh;
	int		width;
	int		height;
}			t_map;

typedef struct s_img
{	
	void	*grass;
	void	*brick;
	void	*coin;
	void	*player[2];
	void	*npc[2];
	void	*door;
	int		sprite_index[2];
}			t_img;

typedef struct s_game
{
	int		all_coins;
	int		col_coins;
	int		walk_cnt;
	int		bonus;
}			t_game;

typedef struct s_valid
{
	int	x;
	int	y;
	int	count_player;
	int	count_exit;
	int	count_enemy;
	int	exit_code;
}			t_valid;

typedef struct s_init
{
	void	*mlx;
	void	*mlx_win;
	t_map	map;
	t_img	img;
	t_game	count;
}			t_init;

//Images
t_img				my_mlx_file_to_image(void *mlx);
void				my_mlx_image_to_window(t_init *game, int width, int height);
void				my_mlx_images_loader(t_init *game);
void				put_anim_sprite(t_init *game, int width, int height);
//Keypress
void				key_press_esc(t_init *game);
void				key_press_w(t_init *game);
void				key_press_s(t_init *game);
void				key_press_a(t_init *game);
void				key_press_d(t_init *game);
int					keypress_settings(int key, t_init *game);
int					quit_game(t_init *game);
//Load Map
int					read_map(t_init *game, char *path);
void				parse_map_2d(t_init *game);
void				print_map(char **map);
int					map_load_settings(t_init *game);
//Check Map
int					check_wall(char **map, int x, int y);
int					check_rectangular(t_init *game);
void				check_coins(t_init *game);
int					count_character(t_valid *check_valid);
int					check_character(t_init *game);
//Check Valid Path
int					get_character(int c);
t_valid				*add_newpath(t_valid *curr_path, int x, int y);
int					check_newpath(char **map, t_valid **check_path,
						int x, int y);
int					valid_path(t_valid *check_valid, char **map, int i, int j);
//Enemy
int					get_enemy_next_pos(t_init *game, int index);
int					set_enemy_next_pos(t_init *game, int i);
int					change_enemy_char_to_upper_n(t_init *game);
int					enemy_patrol(t_init *game);
//So_Long
int					game_load_settings(t_init *game, char *file);
int					main(int ac, char *av[]);
//Libft-standard
char				*ft_strdup_(char *s);
int					ft_strlcpy_(char *dest, char *src, int size);
char				*ft_strjoin_(char *s1, char *s2);
//Libft-itoa
static long int		ft_abs(long int nbr);
static int			ft_len(long int nbr);
char				*ft_itoa(int n);
#endif
