/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:33:35 by sruff             #+#    #+#             */
/*   Updated: 2023/11/07 16:03:29 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (!s && !d)
		return (dest);
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}

//int	main (void)
//{
//	char	buffer[20] = "1234567890987654321";
//	size_t		n = 5;

//	char *d;
//	char *s;

//	d = &buffer[9];
//	s = &buffer[1];

//	printf("Buffer filled: %s\n", (char *)ft_memcpy(d, s, n));
//}
// did too much work and checked for overlapping
//if ((s + n) < d || (d + n) < s)
//	{
//		while (n--)
//		{
//			*d++ = *s++;
//		}
//	}