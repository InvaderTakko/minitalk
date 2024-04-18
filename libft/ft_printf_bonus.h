/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:08:02 by sruff             #+#    #+#             */
/*   Updated: 2023/11/28 18:24:15 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_pf
{
	const char		*str;
	va_list			args;
	unsigned int	len;
	int				error;
	char			*bighex;
	char			*hex;
}					t_pf;

void	print_str(t_pf *pf);
void	print_char(t_pf *pf);
void	print_decimal(long n, t_pf *pf);
void	char_go_brr(char c, t_pf *pf);
int		str_go_brr(char *str, t_pf *pf);
int		print_hex(unsigned int number, char *hexset, int counter, t_pf *pf);
int		loop(unsigned long nbr, char *hexset, int count, t_pf *pf);
int		print_void(t_pf *pf);
void	bonus(t_pf *pf);
int		ft_printf(const char *str, ...);

#endif