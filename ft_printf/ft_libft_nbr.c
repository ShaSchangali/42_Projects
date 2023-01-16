/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:33:57 by sschanga          #+#    #+#             */
/*   Updated: 2022/10/01 23:29:05 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (nb);
}

int	ft_unsigned_nbr(unsigned int nb)
{
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (nb);
}

int	ft_atoi(const char *str, t_struct *root)
{
	int		sign;
	long	nb;
	int		index;

	index = 0;
	nb = 0;
	sign = 1;
	while (str[index] >= '0' && str[index] <= '9')
	{
		nb = nb * 10 + (str[index] - '0');
		if (nb > 2147483647 && sign == 1)
		{
			root->placeholder_pt += 9;
			return (-1);
		}
		if (nb > 2147483648 && sign == -1)
		{
			root->placeholder_pt += 9;
			return (0);
		}
		index++;
	}
	root->placeholder_pt += index - 1;
	return (sign * nb);
}
