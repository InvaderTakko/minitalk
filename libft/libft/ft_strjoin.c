/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:54:49 by sruff             #+#    #+#             */
/*   Updated: 2023/10/30 13:10:12 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sumlen;
	char	*smalloc;

	if (!s1 && !s2)
		return (NULL);
	sumlen = (ft_strlen(s1) + ft_strlen(s2) + 1);
	smalloc = malloc(sumlen * sizeof(char));
	if (!smalloc)
		return (NULL);
	ft_strlcpy(smalloc, s1, ft_strlen(s1) +1);
	ft_strlcpy(&smalloc[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	return (smalloc);
}
