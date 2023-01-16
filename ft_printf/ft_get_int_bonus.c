/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:44:25 by sschanga          #+#    #+#             */
/*   Updated: 2022/10/01 23:52:41 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_get_int(va_list args, const char *placeholder, t_struct *root)
{
	int				d;

	d = va_arg(args, int);
	if (d < 0)
		root->len++;
	if ((root->plus || root->space) && d >= 0)
		root->length--;
	root->length -= ft_get_len(d, *placeholder);
	if (root->length > 0)
		root->len += root->length;
	while (root->length-- > 0)
		ft_putchar(' ');
	if ((root->plus || root->space) && d >= 0)
		root->len++;
	if (root->plus && d >= 0)
		ft_putchar('+');
	else if (root->space && d >= 0)
		ft_putchar(' ');
	ft_putnbr(d);
	root->len += ft_get_len(d, *placeholder);
	return (0);
}

int	ft_get_uint(va_list args, t_struct *root)
{
	unsigned int	u;

	u = va_arg(args, unsigned int);
	if (u == 0)
		root->len++;
	ft_unsigned_nbr(u);
	root->len += ft_get_len_uint(u);
	return (0);
}
