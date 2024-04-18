/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:08:02 by sruff             #+#    #+#             */
/*   Updated: 2023/12/04 18:52:50 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	print_decimal(long n);
int	print_char(int c);
int	print_str(const char *str);
int	print_hex(unsigned int number, char *hexset, int counter);
int	loop(unsigned long n, char *base, int counter);
int	print_void(unsigned long n, char *base, int counter);
int	ft_printf(const char *str, ...);

#endif