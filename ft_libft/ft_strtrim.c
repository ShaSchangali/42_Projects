/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 01:24:26 by sschanga          #+#    #+#             */
/*   Updated: 2022/07/17 23:26:16 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		size_str;
	char		*newstring;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size_str = ft_strlen(s1);
	while (size_str && ft_strchr(set, s1[size_str]))
		size_str--;
	newstring = ft_substr(s1, 0, size_str + 1);
	return (newstring);
}

/*
int main()
{
	char s[] = "helloworld";
	char set[] = "world";
	char *str;
	
	str = ft_strtrim(s, set);
	printf("%s\n", str);
	return (0);
}
*/