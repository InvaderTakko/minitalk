/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:28:32 by sruff             #+#    #+#             */
/*   Updated: 2023/11/07 16:03:29 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}

//int	main(void)
//{
//	char	buffer[20] = "1234567890987654321"; // Example buffer
//	//char		destination[10] = "987654321"; // ascii buffer
//	size_t		len = 5;
//	int c = 53;

//	const char *s;

//	s = &buffer[0];

//	// *(s + 1) is the same as s[1];
//    // call ft_memset and fill buffer
//	//memmove(destination, source, abc);
//	//(char *)ft_memmove(destination, source, abc);
//	// print the buffer
//	//printf("Buffer filled: %s\n", destination);
//	printf("Buffer filled: %s\n", (unsigned char *)ft_memchr(s, c, len));
//	return (0);
//}
