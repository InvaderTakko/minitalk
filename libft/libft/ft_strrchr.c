/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:58:00 by sruff             #+#    #+#             */
/*   Updated: 2023/10/23 18:48:06 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*flag;
	char	*str;

	str = (char *)s;
	flag = NULL;
	while (*str)
	{
		if (*str == (char)c)
		{
			flag = str;
		}
		str++;
	}
	if ((char)c == '\0')
		return (str);
	return (flag);
}

//int	main(void)
//{
//	char	buffer[20] = "123456789A123456A789"; // Example buffer
//	int	search = 'A'; // ASCII value of character to fill the buffer with

//	char *s;

//	s = &buffer[1];
//    // call ft_memset and fill buffer
//	// print the buffer
//	printf("Buffer filled: %s\n", ft_strrchr(s, search));
//	return (0);
//}
