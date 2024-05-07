/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:53:27 by sruff             #+#    #+#             */
/*   Updated: 2024/05/07 15:53:32 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(100);
		bit++;
	}
	// ft_printf("Length sent\n");
}
// send the bits with magic
void	send_bits(pid_t pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8) // 8 bits in a byte
		{
			if ((str[i] & (1 << j)) != 0) // check if bit j is 1 and bitshift
			{
				// ft_printf("%d\n", j);
				if (kill(pid, SIGUSR1) == -1)
				{
					ft_printf("Computer says no 1\n"); // pick better error message
					exit(EXIT_FAILURE);
				}
			}
			else // if bit is 0
			{
				if (kill(pid, SIGUSR2) == -1)
				{
					ft_printf("Computer says no 0\n"); // pick better error message
					// perror("kill");
					exit(EXIT_FAILURE);
				}
			}
			// info->si_signo = ft_strlen(str);
			j++;
			usleep(100);// random sleep value 100 looks good
		}
		i++;
	}
}



// void	sig_handler_c(int n, siginfo_t *info, void *context)
// {
// 	// static int	i;

// 	(void)context;
// 	(void)info;
// 	(void)n;
// 	// g_receiver = 1;
// 	// if (n == SIGUSR2)
// 	// 	i++;
// 	// else if (n == SIGUSR1)
// 	// 	ft_putstrnbr_fd("Num of bytes received -> ", i / 8);
// }
// check if server is alive
void	recieve_answer(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal == SIGUSR1)
	{
		ft_printf("Great Success\nVery nice\n"); // pick better message
		exit(EXIT_SUCCESS);
	}
	else if (signal == SIGUSR2)
	{
		ft_printf("Blyat\n"); // pick better message
		exit(EXIT_FAILURE);
	}
}
int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;
	siginfo_t			info;
	

	sigemptyset(&sa.sa_mask); // initalize
	// sigaction = revieve_answer(getpid());
	pid = ft_atoi(argv[1]);
	// pid = 1234;
	sa.sa_flags = SA_RESTART | SA_SIGINFO; // set flags or inialize???
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) == 0)
		{
			ft_printf("Error: Empty string\n");
			return (1);
		}

		pid = ft_atoi(argv[1]);
		// sa.sa_handler = &recieve_answer; // set handler
		sa.sa_sigaction = recieve_answer;
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			ft_printf("SIGURSR Error\n", 1);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			ft_printf("SIGUSR Error\n", 1);
		// ft_printf("PID : %d\n", pid);
		send_str_len(pid, ft_strlen(argv[2]));
		send_bits(pid, argv[2]);
		(void)info;
		while (1)
			pause();
		// pause(); // not sure if needed
		EXIT_SUCCESS;

	}
	else
	{
			return (1);
	}

	return (0);
}

// i am clueless if i can just send the string bit by bit and print it bit by bit
// or if i need to check the length send the lenght decode the lenght and then malloc
