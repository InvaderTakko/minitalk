/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:02:03 by sruff             #+#    #+#             */
/*   Updated: 2023/10/31 17:36:32 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd(nbr % 10 + '0', fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}

//int main(void)
//{
//	ft_putnbr_fd(100, 1);
//	return 0;
//}

//void	ft_putnbr_fd(int n, int fd)
//{
//	char		buff[20];
//	int			i;
//	int			len;
//	long int	nbr;

//	i = 19;
//	len = 0;
//	nbr = n;
//	if (nbr == 0)
//		write(fd, "0", 1);
//	if (nbr < 0)
//	{
//		write(fd, "-", 1);
//		nbr *= -1;
//	}
//	while (nbr > 0)
//	{
//		buff[i--] = nbr % 10 + '0';
//		nbr /= 10;
//		len++;
//	}
//	i = 20 - len;
//	while (i <= 19)
//		write(fd, &buff[i++], 1);
//}