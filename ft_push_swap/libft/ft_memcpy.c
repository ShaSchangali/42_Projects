/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:58:16 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:58:17 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char	*csrc;
	unsigned char		*cdst;
	size_t				temp;

	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	temp = 0;
	if (!dst && !src)
		return (NULL);
	while (temp < n)
	{
		cdst[temp] = csrc[temp];
		temp++;
	}
	return (cdst);
}
