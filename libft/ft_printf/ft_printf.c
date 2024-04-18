/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:16:50 by sruff             #+#    #+#             */
/*   Updated: 2023/11/28 18:21:41 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <unistd.h>
//#include <stdarg.h>
#include "ft_printf.h"

int	print_char(int c)
{
	if ((write(1, &c, 1)) < 0)
		return (-1);
	else
		return (1);
}

int	print_str(const char *str)
{
	int	counter;

	counter = 0;
	if (str == NULL)
		return (print_str("(null)"));
	while (*str)
	{
		if ((write(1, str, 1)) < 0)
			return ((-1));
		else
		{
			counter++;
			str++;
		}
	}
	return (counter);
}

static int	check_type(const char *str, va_list args)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (*str == 'c')
		return (print_char(va_arg(args, int)));
	else if (*str == 's')
		return (print_str(va_arg(args, char *)));
	else if (*str == 'd')
		return (print_decimal(va_arg(args, int)));
	else if (*str == 'i')
		return (print_decimal(va_arg(args, int)));
	else if (*str == 'X')
		return (print_hex(va_arg(args, unsigned int), "0123456789ABCDEF", 0));
	else if (*str == 'x')
		return (print_hex(va_arg(args, unsigned int), "0123456789abcdef", 0));
	else if (*str == 'u')
		return (print_decimal(va_arg(args, unsigned int)));
	else if (*str == 'p')
	{
		return (print_void((unsigned long)(va_arg(args, void *)), hex, 0));
	}
	else
		return (print_char('%'));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;
	int		temp;

	counter = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			temp = check_type(++str, args);
			if (temp < 0)
				return ((-1));
			counter += temp;
		}
		else
		{
			temp = write (1, str, 1);
			if (temp < 0)
				return ((-1));
			counter += temp;
		}
		str++;
	}
	return (counter);
}

//int main(void)
//{
//	//ft_printf("Print this -> %c\nand this: %c\n", '$', '#');
//	//ft_printf("Print this -> %s\nand this: %s\n", "", "");
//	//ft_printf("Print this -> %c\nand this: %c\n", '$', '#');
//	ft_printf("Print this -> %d\nand this: %d\n", -1234, 1234);
//	ft_printf("Print this -> %x\nand this: %d\n", -1, 1234);

//	printf("\n\n\n");

//	return 0;
//}