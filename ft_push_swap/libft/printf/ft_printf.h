/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:57:06 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:57:07 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_unsigned_address(unsigned long long address);
int	ft_putstr(char const *s);
int	ft_unsigned_ten(unsigned int base);
int	ft_hexadecimal(unsigned long long hex, char x);
int	ft_putnbr(int nbr);
int	ft_putchar(char c);
int	ft_check_specifier(char str, va_list specifier);
int	ft_printf(const char *s, ...);

#endif