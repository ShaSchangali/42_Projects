/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:10:54 by sschanga          #+#    #+#             */
/*   Updated: 2022/10/02 19:43:16 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_struct
{
	int			len;
	const char	*placeholder_pt;
	int			num;
	int			width;
	int			hash;
	int			plus;
	int			space;
	int			length;
}	t_struct;

void		ft_find_mandatory_args(va_list args, t_struct *root);
const char	*ft_get_args(va_list args, t_struct *root);
const char	*ft_read_text(t_struct *root);
int			ft_printf(const char *placeholder, ...);
int			ft_get_str(va_list args, t_struct *root);
int			ft_get_char(va_list args, t_struct *root);
int			ft_get_precent(t_struct *root);
int			ft_get_int(va_list args, const char *placeholder, t_struct *root);
int			ft_get_uint(va_list args, t_struct *root);
int			ft_get_len(int nbr, char placeholder);
int			ft_get_len_hash(unsigned long long nbr);
int			ft_get_len_hex(unsigned long long nbr);
int			ft_get_len_uint(unsigned int nbr);
int			ft_print_hex(unsigned long long x, const char *placeholder);
int			ft_get_hex(va_list args, const char *placeholder, t_struct *root);
int			ft_get_hex_upper(va_list args,
				const char *placeholder, t_struct *root);
int			ft_get_ptr(va_list args, const char *placeholder, t_struct *root);
int			ft_strlen(const char *str);
char		*ft_strchr(const char *s);
int			ft_putchar(char c);
void		ft_putstr(char *s);
int			ft_toupper(int ch);
int			ft_putnbr(int nb);
int			ft_unsigned_nbr(unsigned int nb);
int			ft_atoi(const char *str, t_struct *root);
#endif
