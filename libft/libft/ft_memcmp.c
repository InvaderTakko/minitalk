/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:18:15 by sruff             #+#    #+#             */
/*   Updated: 2023/11/07 16:03:29 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && n - 1 > i)
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

//int	main(void)
//{
//	//char	buffer[20] = "123456'\0'890987654321"; // Example buffer
//	//char	buffer1[20] = "1234567890987654321";
//	 char buffer[] = {'I','n','d','i','a','\0','1'};
//	 char buffer1[] = {'I','n','d','i','a','\0','2'};
//	//char		destination[10] = "987654321"; // ascii buffer
//	size_t		len = 6;

//	const char *s1;
//	const	char *s2;

//	s1 = &buffer[0];
//	s2 = &buffer1[0];

//	// *(s + 1) is the same as s[1];
//    // call ft_memset and fill buffer
//	//memmove(destination, source, abc);
//	//(char *)ft_memmove(destination, source, abc);
//	// print the buffer
//	//printf("Buffer filled: %s\n", destination);
//	printf("Buffer filled: %d\n", ft_memcmp(s1, s2, len));
//	return (0);
//}