/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:08:50 by sschanga          #+#    #+#             */
/*   Updated: 2022/11/05 21:15:31 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strdup_(char *s)
{
	char	*buffer;
	int		size;
	int		i;

	buffer = NULL;
	size = ft_strlen(s);
	i = 0;
	buffer = malloc(size + 1);
	if (!(buffer))
	{
		return (NULL);
	}
	while (s[i] && s[i] != '\n')
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

int	ft_strlcpy_(char *dest, char *src, int size)
{
	int	src_len;
	int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
	{
		return (src_len);
	}
	while (i < size - 1 && *src && *src != '\n')
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (src_len);
}

char	*ft_strjoin_(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup_(s2));
	else if (s2 == NULL)
		return (ft_strdup_(s1));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc(i + j);
	if (!(str))
		return (NULL);
	ft_strlcpy_(str, s1, i + 1);
	ft_strlcpy_(str + i, s2, j + 1);
	free(s1);
	free(s2);
	return (str);
}
