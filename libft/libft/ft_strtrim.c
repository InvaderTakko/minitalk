/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:39:15 by sruff             #+#    #+#             */
/*   Updated: 2023/11/09 16:46:36 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	strlen;
	int		i;

	i = 0;
	strlen = ft_strlen(s1);
	if (s1[0] == '\0')
		return (ft_substr(s1, i, strlen - i + 1));
	while (ft_strchr(set, s1[i]) != 0)
		i++;
	while (ft_strrchr(set, s1[strlen]) != 0)
		strlen--;
	return (ft_substr(s1, i, strlen - i + 1));
}
// int main(void)
// {
//     printf("%s\n", ft_strtrim(" lorem ipsum dolor sit  translate", " "));

//     return (0);
// }