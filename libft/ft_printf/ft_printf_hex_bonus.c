/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:14:13 by sruff             #+#    #+#             */
/*   Updated: 2023/11/28 18:22:20 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
//#include <stdio.h>
//#include <unistd.h>
//#include <stdarg.h>

int	print_hex(unsigned int number, char *hexset, int counter, t_pf *pf)
{
	int	temp;

	temp = 0;
	if (number > 15)
	{
		temp = print_hex(number / 16, hexset, counter, pf);
		if (temp < 0)
			return ((-1));
		counter += temp;
	}
	char_go_brr(hexset[number % 16], pf);
	if (pf->error != -1)
		counter++;
	else
		return ((-1));
	return (counter);
}

//int	main(void)
//{
//	print_hex(10, "0123456789ABCDEF");
//	printf("show me the hex: %X\n", 10);
//	return 0;
//}