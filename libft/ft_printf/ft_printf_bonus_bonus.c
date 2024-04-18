/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:07:10 by sruff             #+#    #+#             */
/*   Updated: 2023/11/28 18:25:47 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	plus(t_pf *pf)
{
	int	i;

	i = 0;
	if (*pf->str == '+')
	{
		pf->str++;
		i = va_arg(pf->args, int);
		if (i >= 0)
		{
			char_go_brr('+', pf);
			print_decimal(i, pf);
		}
		else
			print_decimal(i, pf);
	}
}

static void	hash(t_pf *pf)
{
	int	i;

	i = 0;
	if (*pf->str == ' ')
	{
		pf->str++;
		if (*pf->str == 'd' || *pf->str == 'i')
		{
			i = va_arg(pf->args, int);
			if (i < 0)
				print_decimal(i, pf);
			else
			{
				char_go_brr(' ', pf);
				print_decimal(i, pf);
			}
		}
		if (*pf->str == 's')
			str_go_brr(va_arg(pf->args, char *), pf);
	}
	plus(pf);
}

void	bonus(t_pf *pf)
{
	unsigned int	u;

	u = 0;
	if (*pf->str == '#')
	{
		u = va_arg(pf->args, unsigned int);
		pf->str++;
		if (u == 0)
			char_go_brr('0', pf);
		else if (*pf->str == 'x')
		{
			str_go_brr("0x", pf);
			print_hex(u, pf->hex, 0, pf);
		}
		else if (*pf->str == 'X')
		{
			str_go_brr("0X", pf);
			print_hex(u, pf->bighex, 0, pf);
		}
	}
	hash(pf);
}
