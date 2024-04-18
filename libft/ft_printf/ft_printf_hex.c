/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:14:13 by sruff             #+#    #+#             */
/*   Updated: 2023/11/28 18:22:11 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>
//#include <unistd.h>
//#include <stdarg.h>

int	print_hex(unsigned int number, char *hexset, int counter)
{
	int	temp;

	temp = 0;
	if (number > 15)
	{
		temp = print_hex(number / 16, hexset, counter);
		if (temp < 0)
			return ((-1));
		counter += temp;
	}
	if ((print_char(hexset[number % 16])) > 0)
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