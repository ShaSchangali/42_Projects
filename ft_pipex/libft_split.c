/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:14:51 by sschanga          #+#    #+#             */
/*   Updated: 2022/11/30 19:53:20 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free(char **str_free)
{
	int	i;

	i = 0;
	while (str_free[i])
	{
		free(str_free[i]);
		str_free[i] = NULL;
		i++;
	}
	free(str_free);
	str_free = NULL;
}

static char	*ft_str_cpy(char const *str, char c)
{
	char	*dest;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	count_words(char const *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			i++;
			while (*str && *str != c)
				str++;
		}
	}
	return (i);
}

static int	create_word(char const **s, char	***dest, char c, int *i)
{
	if (**s && **s != c)
	{
		(*dest)[*i] = ft_str_cpy(*s, c);
		if ((*dest)[*i] == NULL)
		{
			ft_free((*dest));
			return (0);
		}
		(*i)++;
		while (**s && **s != c)
			(*s)++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!s || !dest)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (create_word(&s, &dest, c, &i) == 0)
			return (NULL);
	}
	dest[i] = NULL;
	return (dest);
}
