/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:30:27 by sschanga          #+#    #+#             */
/*   Updated: 2022/07/14 00:15:09 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*pt_str1;
	unsigned char	*pt_str2;

	pt_str1 = (unsigned char *)s1;
	pt_str2 = (unsigned char *)s2;
	i = 0;
	while (i < n && pt_str1[i] == pt_str2[i])
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return (pt_str1[i] - pt_str2[i]);
}

/*
int main()
{
	char	str[] = "abca";
	char	str2[] = "abcf";
	printf("%d\n", ft_memcmp(str, str2, 4));
	return (0);
}
*/
