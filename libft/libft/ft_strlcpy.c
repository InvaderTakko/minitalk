/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:58:26 by sruff             #+#    #+#             */
/*   Updated: 2023/11/07 15:27:02 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (*(src + i) && i < dstsize - 1)
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	while (*(src + i))
		i++;
	return (i);
}

//int	main(void)
//{
//	char	buffer[20] = "1234567890987654321";
//	size_t	n = 5;

//	char *d;
//	const char *s;

//	d = &buffer[9];
//	s = &buffer[1];

//	printf("Buffer filled: %lu\n", ft_strlcpy(d, s, n));
//}