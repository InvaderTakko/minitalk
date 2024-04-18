/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:41:04 by sruff             #+#    #+#             */
/*   Updated: 2023/11/07 15:54:21 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_cnt;
	size_t	lenstr;

	dst_cnt = 0;
	while (*dst && dstsize > dst_cnt)
	{
		dst++;
		dst_cnt++;
	}
	lenstr = ft_strlcpy(dst, src, dstsize - dst_cnt);
	return (lenstr + dst_cnt);
}

//printf("Buffer filled: %s\n", dst);
//int	main(void)
//{
//	char	buffer[20] = "123456789";
//	char	buffers[] = "123";
//	size_t	n = 20;

//	char *d;
//	const char *s;

//	d = &buffer[0];
//	s = &buffers[0];
//	strlcat(d, s, n)

//	printf("Buffer filled: %lu\n", ft_strlcat(d, s, n));
//}