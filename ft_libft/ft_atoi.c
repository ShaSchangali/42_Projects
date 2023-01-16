/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:49:13 by sschanga          #+#    #+#             */
/*   Updated: 2022/07/17 00:51:35 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char e)
{
	return (e == ' ' || e == '\f' || e == '\r' || e == '\v'
		|| e == '\t' || e == '\n');
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	nb;
	int		index;

		index = 0;
		nb = 0;
		sign = 1;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		nb = nb * 10 + (str[index] - '0');
		if (nb > 2147483647 && sign == 1)
			return (-1);
		if (nb > 2147483648 && sign == -1)
			return (0);
		index++;
	}
	return (sign * nb);
}

/*
int main()
{
	char s[] = "-920368";
	printf("%d\n", ft_atoi(s));
	return 0;
}
*/