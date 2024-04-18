/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:18:57 by sruff             #+#    #+#             */
/*   Updated: 2023/11/28 18:22:27 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	print_decimal(long n)
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
	return (print_str(&numstr[0]));
}
