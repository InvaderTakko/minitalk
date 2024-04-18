/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:54:45 by sruff             #+#    #+#             */
/*   Updated: 2024/04/09 10:01:04 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

// char	*ft_strchr(const char *s, int c)
// {
// 	char	*str;

// 	str = (char *)s;
// 	if (str == NULL)
// 		return (NULL);
// 	while (*str)
// 	{
// 		if (*str == (char)c)
// 			return (str);
// 		str++;
// 	}
// 	if ((char)c == '\0')
// 		return (str);
// 	return (NULL);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!src)
// 		return (0);
// 	if (dstsize != 0)
// 	{
// 		while (*(src + i) && i < dstsize - 1)
// 		{
// 			*(dst + i) = *(src + i);
// 			i++;
// 		}
// 		*(dst + i) = '\0';
// 	}
// 	while (*(src + i))
// 		i++;
// 	return (i);
// }

// size_t	ft_strlen(const char *s)
// {
// 	int	l;

// 	l = 0;
// 	if (!s)
// 		return (0);
// 	while (s[l] != '\0')
// 		l++;
// 	return (l);
// }

char	*ft_strjoin1(char const *s1, char const *s2)
{
	char		*ptr;
	size_t		i;
	size_t		j;

	if (!s1)
	{
		if (!s2 || !*s2)
			return (NULL);
		ptr = malloc(ft_strlen(s2) + 1);
		if (!ptr)
			return (NULL);
		return (ft_strlcpy(ptr, s2, ft_strlen(s2) + 1), ptr);
	}
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		ptr[i++] = s1[j++];
	while (*s2 != '\0')
		ptr[i++] = *(s2++);
	return (ptr[i] = '\0', ptr);
}

char	*ft_substr1(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	char			*subm;
	size_t			slen;

	sub = (char *)s;
	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen || (start == 0 && len == 0))
		return ("");
	if (slen - start < len)
		len = slen - start;
	subm = malloc((len + 1) * sizeof(char));
	if (!subm)
		return (NULL);
	ft_strlcpy(subm, sub + start, len + 1);
	return (subm);
}
