/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:58:06 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:58:07 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*dst;
	unsigned char		search;
	size_t				count;

	dst = (const unsigned char *)s;
	search = (unsigned char )c;
	count = 0;
	while (count < n)
	{
		if (*dst == search)
			return ((void *)dst);
		dst++;
		count++;
	}
	return (0);
}
