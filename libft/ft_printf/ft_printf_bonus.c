/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:16:50 by sruff             #+#    #+#             */
/*   Updated: 2024/04/08 21:35:01 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <unistd.h>
//#include <stdarg.h>
#include "ft_printf_bonus.h"

void	char_go_brr(char c, t_pf *pf)
{
	if ((write(1, &c, 1)) < 0)
		pf->error = -1;
	else
		pf->len++;
}

int	str_go_brr(char *str, t_pf *pf)
{
	int	counter;

	counter = 0;
	if (str == NULL)
		str = "(null)";
	while (*str && pf->error != -1)
	{
		char_go_brr(*str, pf);
		if (pf->error == -1)
			return (0);
		str++;
	}
	return (counter);
}

static void	check_type(t_pf *pf)
{
	pf->str++;
	if (*pf->str == 'c')
		print_char(pf);
	else if (*pf->str == 's')
		print_str(pf);
	else if (*pf->str == 'd')
		print_decimal(va_arg(pf->args, int), pf);
	else if (*pf->str == 'i')
		print_decimal(va_arg(pf->args, int), pf);
	else if (*pf->str == 'X')
		print_hex(va_arg(pf->args, unsigned int), pf->bighex, 0, pf);
	else if (*pf->str == 'x')
		print_hex(va_arg(pf->args, unsigned int), pf->hex, 0, pf);
	else if (*pf->str == 'u')
		print_decimal(va_arg(pf->args, unsigned int), pf);
	else if (*pf->str == 'p')
		print_void(pf);
	else if (*pf->str == '%')
		char_go_brr('%', pf);
	else if (*pf->str == '#' || *pf->str == ' ' || *pf->str == '+')
		bonus(pf);
}

int	ft_printf(const char *str, ...)
{
	t_pf	pf;

	pf.str = str;
	pf.len = 0;
	pf.error = 0;
	pf.bighex = "0123456789ABCDEF";
	pf.hex = "0123456789abcdef";
	va_start(pf.args, str);
	while (*pf.str && pf.error != -1)
	{
		if (*pf.str == '%')
			check_type(&pf);
		else
			char_go_brr((char)*pf.str, &pf);
		pf.str++;
	}
	if (pf.error == -1)
		return (pf.error);
	return (pf.len);
}

// int main(void)
// {
// 	void	*ptr;
// 	//ft_printf("Print this -> %c\nand this: %c\n", '$', '#');
// 	//ft_printf("Print this -> %s\nand this: %s\n", "", "");
// 	//ft_printf("Print this -> %s\nand this: %s\n", "asd134", "6780abc");
// 	//ft_printf("Print this -> %c\nand this: %c\n", '$', '#');
// 	//ft_printf("Print this 123 -> %d\nand this: %d\n", -1234, 1234);
// 	//ft_printf("Print this 123 -> %p\nand this: %%d\n", ptr, 1234);
// 	ft_printf("-> %X\n ->%s\n and some of this: %x\n", -1, "", -1234);
// 	printf("-> %#X\n->%s\n and some of this: %#x\n", -1, "", -1234);

// 	printf("\n------------------\n\n");
// 	   printf("Hex |%#x|\n %#X\n", 123, 123);
// 	ft_printf("Hex |%#x|\n %#X\n", 123, 123);

// 	printf("\n\n\n");

// 	return 0;
// }