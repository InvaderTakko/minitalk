/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:16:23 by sruff             #+#    #+#             */
/*   Updated: 2024/04/15 16:32:29 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) == 0)
		{
			ft_printf("Error: Empty string\n");
			return (1);
		}
		// actual useful code here
	}
	else
	{
		// wrong input here
		return (1);
	}
	return (0);
}
