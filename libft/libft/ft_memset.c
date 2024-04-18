/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:04:06 by sruff             #+#    #+#             */
/*   Updated: 2023/11/03 18:18:04 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	l;

	str = (char *)b;
	l = 0;
	while (l < len)
	{
		str[l] = c;
		l++;
	}
	return (b);
}

//int	main(void)
//{
//	char	buffer[20] = "1234567890123456789"; // Example buffer
//	int	fill = 'A'; // ASCII value of character to fill the buffer with
//	size_t abc = 5;

//    // call ft_memset and fill buffer
//	// print the buffer
//	printf("Buffer filled: %s\n", (char *)ft_memset(buffer, fill, abc));
//	return (0);
//}
