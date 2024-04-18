/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:15 by sruff             #+#    #+#             */
/*   Updated: 2023/10/31 13:08:00 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	long			nbr;
	char			numstr[21];
	int				digit;
	char			*test;

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
	test = ft_strdup(&numstr[0]);
	return (test);
}
