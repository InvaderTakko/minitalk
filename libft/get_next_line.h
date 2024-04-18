/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:05:30 by sruff             #+#    #+#             */
/*   Updated: 2024/04/09 10:01:55 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct s_gnl
{
	int				fd;
	int				i;
	long			bytes;
	char			*temp;
	char			*next_line;
}					t_gnl;

char	*get_next_line(int fd);
// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
// size_t	ft_strlen(const char *s);
char	*ft_substr1(char const *s, unsigned int start, size_t len);
// char	*ft_strchr(const char *s, int c);
char	*ft_strjoin1(char const *s1, char const *s2);

//int main(void);

#endif