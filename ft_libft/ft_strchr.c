/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:36:03 by sschanga          #+#    #+#             */
/*   Updated: 2022/07/16 22:57:18 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (s[i] == c)
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{ 
    char a[50] = "Hello world";
    printf("result is %s\n", ft_strchr(a, 'e'));
}
*/
