/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:16:23 by sruff             #+#    #+#             */
/*   Updated: 2024/04/16 13:17:41 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "libft/ft_printf_bonus.h"
#include <unistd.h>
// send the bits with magic
void	send_bits(pid_t pid, char *str)
{

}
// check if client recieves the string/prints it
void	recieve_answer(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("Great Success\nVery nice\n");
		exit(EXIT_SUCCESS);
	}
	else if (signal == SIGUSR2)
	{
		ft_printf("Blyat\n");
		exit(EXIT_FAILURE);
	}
}
int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;

	sigemptyset(&sa.sa_mask); // initalize
	sa.sa_flags = SA_RESTART | SA_SIGINFO; // set flags or inialize???
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) == 0)
		{
			ft_printf("Error: Empty string\n");
			return (1);
		}
		pid = ft_atoi(argv[1]);
		sa.sa_handler = recieve_answer; // set handler
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
		{
			ft_printf("Error: sigaction\n");
			return (1);
		}
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
		{
			ft_printf("Error: sigaction\n");
			return (1);
		}
		while (1)
		{
			send_bits(pid, argv[2]);
			pause();
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
