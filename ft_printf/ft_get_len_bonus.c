/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:44:25 by sschanga          #+#    #+#             */
/*   Updated: 2022/10/01 23:52:44 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_get_len(int nbr, char placeholder)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i++;
	if (placeholder == 'd' || placeholder == 'i'
		|| placeholder == 'c' || placeholder == '+' || placeholder == ' ')
	{
		while (nbr)
		{
			nbr /= 10;
			i++;
		}
		return (i);
	}
	return (nbr);
}

int	ft_get_len_hex(unsigned long long nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

int	ft_get_len_uint(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_get_len_hash(unsigned long long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i--;
	while (nbr)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}
