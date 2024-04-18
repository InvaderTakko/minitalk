/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:45:53 by sruff             #+#    #+#             */
/*   Updated: 2023/11/07 16:03:29 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

//int	main(void)
//{
//	char	buffer[20] = "1234567890123456789"; // Example buffer
//	size_t abc = 5;

//    // call ft_bzero and fill buffer
//	ft_bzero(buffer, abc);
//	// print the buffer
//	printf("Buffer filled: %s\n", buffer);
//	return (0);
//}