/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:18:57 by sruff             #+#    #+#             */
/*   Updated: 2023/11/28 18:22:35 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	checkdigits(int digit, long nbr, char *numstr)
{
	long	temp;

	if (nbr == 0)
	{
		digit++;
		numstr[0] = 0;
	}
	temp = nbr;
	while (temp > 0)
	{
		temp /= 10;
		digit++;
	}
	return (digit);
}

void	print_decimal(long n, t_pf *pf)
{
	long			nbr;
	char			numstr[21];
	int				digit;

	nbr = n;
	digit = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		digit++;
		numstr[0] = '-';
	}
	digit = checkdigits(digit, nbr, numstr);
	numstr[digit] = '\0';
	while (nbr >= 10)
	{
		numstr[--digit] = nbr % 10 + '0';
		nbr = (nbr / 10);
	}
	numstr[--digit] = nbr + '0';
	pf->len += str_go_brr((char *)&numstr[0], pf);
}
