/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:07:57 by sruff             #+#    #+#             */
/*   Updated: 2023/10/24 17:18:36 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	plusminus;
	int	number;
	int	flag;

	plusminus = 1;
	number = 0;
	flag = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			plusminus *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57 && flag == 0)
	{
		number = number * 10;
		number = number + *str - 48;
		str++;
		if (!(*str >= '0' && *str <= '9'))
			flag = 1;
	}
	return (number * plusminus);
}
