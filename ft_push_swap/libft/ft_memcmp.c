/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:58:11 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:58:12 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*lens1;
	unsigned char	*lens2;
	int				result;

	lens1 = (unsigned char *)s1;
	lens2 = (unsigned char *)s2;
	result = 0;
	while (n--)
	{
		if (lens1[result] != lens2[result])
			return (lens1[result] - lens2[result]);
		result++;
	}
	return (0);
}
