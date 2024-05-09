/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:51:50 by sruff             #+#    #+#             */
/*   Updated: 2024/05/09 17:00:47 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include "./libft/ft_printf_bonus.h"
# include <stdio.h>
# include <signal.h>
# include <unistd.h>

typedef struct s_server {
	size_t	bit_counter;
	char	*str;
	char	c;
	size_t	str_len;
	int		flag;
	int		pid;
}	t_server;

#endif