/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:10:08 by sruff             #+#    #+#             */
/*   Updated: 2023/11/28 18:22:02 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "ft_printf_bonus.h"

int	loop(unsigned long nbr, char *hexset, int count, t_pf *pf)
{
	int	temp;

	temp = 0;
	if (nbr > 15)
	{
		temp = loop(nbr / 16, hexset, count, pf);
		if (temp < 0)
			return ((-1));
		count += temp;
	}
	if (pf->error == -1)
		return (pf->error);
	char_go_brr(hexset[nbr % 16], pf);
	count++;
	return (count);
}

int	print_void(t_pf *pf)
{
	int				temp;
	unsigned long	n;
	int				counter;

	temp = 0;
	counter = 0;
	n = (unsigned long)va_arg(pf->args, void *);
	str_go_brr("0x", pf);
	temp = loop(n, pf->hex, counter, pf);
	if (pf->error == -1)
		return (pf->error);
	return (temp + 2);
}

//int	main(void)
//{
//	void	*ptr;
//	print_voidptr(ptr, "0123456789abcdef");
//	printf("adress: %p", ptr);
//	return 0;
//}