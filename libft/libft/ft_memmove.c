/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:59:46 by sruff             #+#    #+#             */
/*   Updated: 2023/10/23 15:57:56 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;

	s = (char *)src;
	d = (char *)dst;
	if (!d && !s)
		return (NULL);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d = d + len - 1;
		s = s + len - 1;
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}

//int	main(void)
//{
//	char	buffer[20] = "1234567890987654321"; // Example buffer
//	//char		destination[10] = "987654321"; // ascii to fill the buffer with
//	size_t		len = 5;

//	char *d;
//	char *s;

//	d = &buffer[3];
//	s = &buffer[1];

//	// *(s + 1) is the same as s[1];
//    // call ft_memset and fill buffer
//	//memmove(destination, source, abc);
//	//(char *)ft_memmove(destination, source, abc);
//	// print the buffer
//	//printf("Buffer filled: %s\n", destination);
//	printf("Buffer filled: %s\n", (char *)ft_memmove(d, s, len));
//	return (0);
//}