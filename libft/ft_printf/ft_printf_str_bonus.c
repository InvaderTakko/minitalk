/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:41:35 by sruff             #+#    #+#             */
/*   Updated: 2024/04/09 13:15:30 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	print_str(t_pf *pf)
{
	char	*str;

	str = va_arg(pf->args, char *);
	if (!str)
		str = "(null)";
	while (*str && pf->error != -1)
	{
		if ((write(1, str, 1)) < 0)
			pf->error = -1;
		else
		{
			pf->len++;
			str++;
		}
	}
}

void	print_char(t_pf *pf)
{
	char	c;

	c = va_arg(pf->args, int);
	if ((write(1, &c, 1)) < 0)
		pf->error = -1;
	else
		pf->len++;
}
