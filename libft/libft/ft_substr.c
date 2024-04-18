/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:06:32 by sruff             #+#    #+#             */
/*   Updated: 2023/11/03 18:17:29 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	char			*subm;
	size_t			slen;

	sub = (char *)s;
	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen || (start == 0 && len == 0))
		return (ft_strdup(""));
	if (slen - start < len)
		len = slen - start;
	subm = malloc((len + 1) * sizeof(char));
	if (!subm)
		return (NULL);
	ft_strlcpy(subm, sub + start, len + 1);
	return (subm);
}

	//sub = (char *)s[start];
//int main(void)
//{
//	const char str[] = "Degrading Sanity";
//	unsigned int  start = 3;
//	size_t len = 5;

//	printf("Show me what you got: %s\n", ft_substr(str, start, len));
//}	