/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 00:50:59 by sschanga          #+#    #+#             */
/*   Updated: 2022/11/05 21:35:54 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_character(int c)
{
	return (c == 'E' || c == 'C' || c == 'P');
}

t_valid	*add_newpath(t_valid *curr_path, int x, int y)
{
	int		i;
	t_valid	*new_path;

	i = 0;
	while ((curr_path)[i].x != -1)
		++i;
	new_path = malloc(sizeof(t_valid) * (i + 2));
	if (new_path == NULL)
		exit(1);
	i = 0;
	while ((curr_path)[i].x != -1)
	{
		new_path[i].x = (curr_path)[i].x;
		new_path[i].y = (curr_path)[i].y;
		++i;
	}
	new_path[i].x = x;
	new_path[i].y = y;
	new_path[i + 1].x = -1;
	free(curr_path);
	return (new_path);
}

int	check_newpath(char **map, t_valid **check_path, int x, int y)
{
	int	i;

	i = -1;
	if (x < 0 || y < 0)
		return (0);
	if (map[x] == 0 || map[x][y] == '1' || map[x][y] == 0)
		return (0);
	if (map[x][y] == 'P')
		return (1);
	while ((*check_path)[++i].x != -1)
	{
		if ((*check_path)[i].x == x && (*check_path)[i].y == y)
			return (0);
	}
	*check_path = add_newpath(*check_path, x, y);
	return (check_newpath(map, check_path, x - 1, y)
		|| check_newpath(map, check_path, x + 1, y)
		|| check_newpath(map, check_path, x, y + 1)
		|| check_newpath(map, check_path, x, y - 1));
}

int	valid_path(t_valid *check_valid, char **map, int i, int j)
{
	i = -1;
	j = -1;
	check_valid = malloc(1 * sizeof(t_valid));
	check_valid[0].x = -1;
	while (map[++i] != NULL)
	{
		while (map[i][++j] != 0)
		{
			if (get_character(map[i][j]))
			{
				if (check_newpath(map, &check_valid, i, j) == 0)
				{
					free (check_valid);
					return (1);
				}
				free(check_valid);
				check_valid = malloc(1 * sizeof(t_valid));
				check_valid[0].x = -1;
			}
		}
		j = -1;
	}
	free(check_valid);
	return (0);
}
