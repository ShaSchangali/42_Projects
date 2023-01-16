/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:40:51 by sschanga          #+#    #+#             */
/*   Updated: 2022/10/01 23:33:06 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long x, const char *placeholder)
{
	char	*hex;
	int		result[16];
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	while (x >= 16)
	{
		result[i] = hex[x % 16];
		x = x / 16;
		i++;
	}
	result[i] = hex[x];
	while (i >= 0)
	{
		if (*placeholder == 'X')
			ft_putchar(ft_toupper(result[i--]));
		else
			ft_putchar(result[i--]);
	}
	return (0);
}

int	ft_get_hex(va_list args, const char *placeholder, t_struct *root)
{
	unsigned long long	x;

	x = 0;
	if (*placeholder == 'x')
	{
		x = va_arg(args, unsigned int);
		if (x == 0)
			root->len++;
		if (root->hash && x != 0)
		{
			ft_putstr("0x");
			root->len += 2;
		}
		ft_print_hex((unsigned long)x, placeholder);
		root->len += ft_get_len_hex(x);
	}
	return (0);
}

int	ft_get_hex_upper(va_list args, const char *placeholder, t_struct *root)
{
	unsigned long long	x;

	x = 0;
	x = va_arg(args, unsigned int);
	if (x <= 0)
		root->len++;
	if (root->hash && x != 0)
	{
		ft_putstr("0X");
		root->len += 2;
	}
	ft_print_hex((unsigned long)x, placeholder);
	root->len += ft_get_len_hex(x);
	return (0);
}

int	ft_get_ptr(va_list args, const char *placeholder, t_struct *root)
{
	unsigned long long	p;

	p = va_arg(args, unsigned long long);
	if (p <= 0)
		root->len++;
	ft_putchar('0');
	ft_putchar('x');
	ft_print_hex((unsigned long)p, placeholder);
	root->len += ft_get_len_hex((unsigned long long)p) + 2;
	return (0);
}
