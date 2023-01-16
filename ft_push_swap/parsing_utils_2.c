/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:50:09 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/15 22:23:59 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*parseme(char **argv, int argc)
{
	int		i;
	char	*str;
	char	*temp;

	i = 1;
	temp = ft_strdup(" ");
	while (i < argc)
	{
		str = ft_strjoin(temp, argv[i]);
		if (temp)
			free (temp);
		temp = ft_strjoin(str, " ");
		if (str)
			free (str);
		i++;
	}
	return (temp);
}

unsigned int	ft_get_nb_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

int	error_1(char *tmp)
{
	if (*tmp == '\0')
	{
		free (tmp);
		return (FALSE);
	}
	return (TRUE);
}

int	error_2(char **av, char *tmp, int i, int j)
{
	if (!ft_isdigit(av[j][i]) && av[j][i] != '-'
		&& av[j][i] != '+' && !ft_strchr(" \t\n\v\f\r", av[j][i]))
	{
		free (tmp);
		return (FALSE);
	}
	return (TRUE);
}

int	check_char(char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 1;
	tmp = NULL;
	while (av[j])
	{
		i = 0;
		tmp = ft_strtrim(av[j], " ");
		if (error_1(tmp) == FALSE)
			return (FALSE);
		while (av[j][i])
		{
			if (error_2(av, tmp, i, j) == FALSE)
				return (FALSE);
			i++;
		}
		j++;
		free (tmp);
	}
	return (TRUE);
}
