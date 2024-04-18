/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:39:28 by sruff             #+#    #+#             */
/*   Updated: 2023/10/23 20:03:04 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if ((char)c == '\0')
		return (str);
	return (NULL);
}

//int	main(void)
//{
//	char buffer[] = {'I','n','d','i','a','\0','1'};
//	//char	buffer[20] = "123456789A123456789"; // Example buffer
//	int	search = 'A'; // ASCII value of character to fill the buffer with

//	char *s;

//	s = &buffer[1];
//    // call ft_memset and fill buffer
//	// print the buffer
//	printf("Buffer filled: %s\n", ft_strchr(buffer, search));
//	return (0);
//}
