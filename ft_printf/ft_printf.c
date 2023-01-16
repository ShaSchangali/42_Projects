/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:26:22 by sschanga          #+#    #+#             */
/*   Updated: 2022/10/01 22:48:19 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_find_mandatory_args(va_list args, t_struct *root)
{
	if (*(root->placeholder_pt) == 'd' || *(root->placeholder_pt) == 'i')
		ft_get_int(args, root->placeholder_pt, root);
	else if (*(root->placeholder_pt) == 'u')
		ft_get_uint(args, root);
	else if (*(root->placeholder_pt) == 's')
		ft_get_str(args, root);
	else if (*(root->placeholder_pt) == 'c')
		ft_get_char(args, root);
	else if (*(root->placeholder_pt) == 'x')
		ft_get_hex(args, root->placeholder_pt, root);
	else if (*(root->placeholder_pt) == 'X')
		ft_get_hex_upper(args, root->placeholder_pt, root);
	else if (*(root->placeholder_pt) == 'p')
		ft_get_ptr(args, root->placeholder_pt, root);
	else if (*(root->placeholder_pt) == '%')
		ft_get_precent(root);
}

const char	*ft_get_args(va_list args, t_struct *root)
{	
	root->hash = 0;
	root->plus = 0;
	root->space = 0;
	root->length = -1;
	while (!(*(root->placeholder_pt) == 'd' || *(root->placeholder_pt) == 'i'
			|| *(root->placeholder_pt) == 'u' || *(root->placeholder_pt) == 's'
			|| *(root->placeholder_pt) == 'c' || *(root->placeholder_pt) == 'x'
			|| *(root->placeholder_pt) == 'X' || *(root->placeholder_pt) == 'p'
			|| *(root->placeholder_pt) == '%'))
	{
		if (*(root->placeholder_pt) == '#')
			root->hash = 1;
		if (*(root->placeholder_pt) == '+')
			root->plus = 1;
		if (*(root->placeholder_pt) == ' ')
			root->space = 1;
		if (*(root->placeholder_pt) >= '0' && *(root->placeholder_pt) <= '9')
			root->length = ft_atoi(root->placeholder_pt, root);
		(root->placeholder_pt)++;
	}
	ft_find_mandatory_args(args, root);
	(root->placeholder_pt)++;
	return (root->placeholder_pt);
}

const char	*ft_read_text(t_struct *root)
{
	char	*next;

	next = ft_strchr(root->placeholder_pt);
	if (next)
	{
		root->width = next - root->placeholder_pt;
	}
	else
	{
		root->width = ft_strlen(root->placeholder_pt);
	}
	write(1, root->placeholder_pt, root->width);
	root->len += root->width;
	while (*(root->placeholder_pt) && *(root->placeholder_pt) != '%')
	{
		root->placeholder_pt++;
	}
	return (root->placeholder_pt);
}

int	ft_printf(const char *placeholder, ...)
{
	va_list		args;
	t_struct	root;

	root.len = 0;
	va_start(args, placeholder);
	root.placeholder_pt = placeholder;
	while (*(root.placeholder_pt))
	{
		if (*(root.placeholder_pt) == '%')
		{
			root.placeholder_pt++;
			root.placeholder_pt = ft_get_args(args, &root);
		}
		else
		{
			root.placeholder_pt = ft_read_text(&root);
		}
	}
	va_end(args);
	return (root.len);
}
