/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:22:55 by sruff             #+#    #+#             */
/*   Updated: 2024/04/09 09:23:17 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

static int	get_index(char const *s, char c, int index)
{
	int	i;

	i = index;
	while (s[i])
	{
		if (s[i] != c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

static int	word_counter(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
		{
			words++;
		}
		i++;
	}
	return (words);
}

static int	get_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static char	**free_array(char **ptrarray, int index)
{
	while (0 <= index)
	{
		free(ptrarray[index]);
		index--;
	}
	free(ptrarray);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		i;
	int		index;
	char	**ptrarray;
	int		wlen;

	i = 0;
	index = get_index(s, c, i);
	words = word_counter(s, c);
	ptrarray = malloc((words + 1) * sizeof(char *));
	if (!ptrarray)
		return (0);
	ptrarray[words] = NULL;
	while (i < words)
	{
		wlen = get_wordlen(&s[index], c);
		ptrarray[i] = ft_substr(s, index, wlen);
		if (!ptrarray[i])
			return (free_array(ptrarray, i));
		index = get_index(s, c, index + wlen);
		i++;
	}
	return (ptrarray);
}

//int	main(void)
//{
//	char	array[] = " teste wie viele woerter";
//	char	c = ' ';
//	char	**wa;
//	int	i;

//	i = 0;

//	//printf("how many words %s\n", ft_split(array, c));
//	wa = ft_split("      split       this for   me  !       ", ' ');
//	while (wa[i])
//	{
//		printf("%sa\n", wa[i]);
//		i++;
//	}
//}
// gcc *.c *.h to compile