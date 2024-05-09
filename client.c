/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:16:23 by sruff             #+#    #+#             */
/*   Updated: 2024/05/09 15:59:36 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_exit(char *message, int mode)
{
	if (mode == 1)
	{
		ft_printf("%s\n", message);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf("%s\n", message);
		exit(EXIT_FAILURE);
	}
}

void	send_str_len(pid_t pid, size_t len)
{
	size_t	bit;

	bit = 0;
	while (bit < (sizeof(size_t) * 8))
	{
		if ((len & ((size_t)1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bit++;
	}
}

void	send_bits(pid_t pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if ((str[i] & (1 << j)) != 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					print_exit("Could not send signal", 0);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					print_exit("Could not send signal", 0);
			}
			j++;
			usleep(50);
		}
		i++;
	}
}

void	recieve_answer(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal == SIGUSR1)
		print_exit("Server recieved message", 1);
	else if (signal == SIGUSR2)
		print_exit("Error during sending", 0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) == 0)
			print_exit("Error: Empty string", 0);
		pid = ft_atoi(argv[1]);
		sa.sa_sigaction = recieve_answer;
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			print_exit("Could not send signal", 0);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			print_exit("Could not send signal", 0);
		send_str_len(pid, ft_strlen(argv[2]));
		send_bits(pid, argv[2]);
		while (1)
			pause();
		exit(EXIT_SUCCESS);
	}
	print_exit("enter: ./client PID \"string\"", 0);
	return (0);
}
