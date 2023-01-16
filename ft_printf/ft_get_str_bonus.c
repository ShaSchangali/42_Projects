/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:57:53 by sschanga          #+#    #+#             */
/*   Updated: 2022/10/01 23:53:09 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_get_str(va_list args, t_struct *root)
{
	char	*s;

	s = NULL;
	s = va_arg(args, char *);
	if (!s)
	{
		root->length -= 6;
		if (root->length > 0)
			root->len += root->length;
		while (root->length-- > 0)
			ft_putchar(' ');
		write(1, "(null)", 6);
		root->len += 6;
	}
	else
	{	
		root->length -= ft_strlen(s);
		if (root->length > 0)
			root->len += root->length;
		while (root->length-- > 0)
			ft_putchar(' ');
		ft_putstr(s);
		root->len += ft_strlen(s);
	}
	return (0);
}

int	ft_get_char(va_list args, t_struct *root)
{
	int	c;

	c = va_arg(args, int);
	ft_putchar(c);
	root->len += 1;
	return (0);
}

int	ft_get_precent(t_struct *root)
{
	ft_putchar('%');
	root->len++;
	return (0);
}
