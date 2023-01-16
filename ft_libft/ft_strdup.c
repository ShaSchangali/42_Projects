/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:41:05 by sschanga          #+#    #+#             */
/*   Updated: 2022/07/14 01:44:38 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*buffer;
	size_t	i;

	i = 0;
	buffer = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!buffer)
		return (NULL);
	while (s[i] != '\0')
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i++] = '\0';
	return (buffer);
}

/*
int main(void)
{
	char	s[] = "bla";
	char	*str;

	str = ft_strdup(s);
	printf("%s\n", str);
	return (0);
}
*/
