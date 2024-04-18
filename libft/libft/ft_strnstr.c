/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:14:13 by sruff             #+#    #+#             */
/*   Updated: 2023/11/07 16:03:29 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	char			*h;
	char			*n;

	if (!*needle)
		return ((char *)haystack);
	while (len >= 1 && *haystack)
	{
		h = (char *)haystack;
		n = (char *)needle;
		i = len;
		while (*n && *h && *n == *h && i > 0)
		{
			n++;
			h++;
			i--;
		}
		if (!*n)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

//int	main(void)
//{
//	char	needle[] = "123"; // Example buffer
//	char	haystack[] = "this code sucks so bad";
//	size_t len = 20;

//	const char *n;
//	const	char *h;

//	n = &needle[0];
//	h = &haystack[0];

//	printf("Surely this is correct: %s\n", ft_strnstr(h, n, len));
//}