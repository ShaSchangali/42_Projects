/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:59:13 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:59:14 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	index;
	char			*dst;

	index = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	dst = malloc(sizeof(*dst) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == 0)
		return (0);
	while (*s1 != '\0')
		dst[index++] = *s1++;
	while (*s2 != '\0')
		dst[index++] = *s2++;
	dst[index] = '\0';
	return (dst);
}
