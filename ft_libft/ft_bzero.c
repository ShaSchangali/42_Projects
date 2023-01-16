/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:50:25 by sschanga          #+#    #+#             */
/*   Updated: 2022/07/15 01:33:10 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/*
int main()
{
    char str1[] = "test";
    ft_bzero(str1 + 2, 1);
    printf("test %s\n", str1);
    
    char str2[] = "flash";
    bzero(str2 + 2, 1);
    printf("flash %s\n", str2);
}
*/