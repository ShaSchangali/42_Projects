/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:07:07 by sschanga          #+#    #+#             */
/*   Updated: 2022/07/14 00:22:53 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)s);
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i + j] == to_find[j] && (i + j) < len)
		{
			if (s[i + j] == '\0' && to_find[j] == '\0')
			{
				return ((char *)&s[i]);
			}
			j++;
		}
		if (to_find[j] == '\0')
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (0);
}

/*
int main()
{
	const char str[10] = "testcall";
	const char finder[10] = "st";
	char *find_str;
	
	find_str = ft_strnstr(str,finder,4);
	printf("%s\n", find_str);
	return (0);
}
*/
