/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:16:10 by sruff             #+#    #+#             */
/*   Updated: 2024/04/18 17:37:59 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

char 	*decode_strlen()
{	
	pid
	static long len;
	static count;

	if (count == int or long size)
	{
		string = malloc(len);
		count++;
	}
	

	return (string);
	
}
void recieve_bits()
{
	decode_str_len();
}
// test later if i need void *context
void sig_handler(int signum, siginfo_t *info)
{
	static int bit_counter;
	static char c;
	static int str_len;
	static int pid;

	bit_counter = 0;
	c = 0;
	if (pid == 0)
		pid = info->si_pid;
	str_len = info->si_signo;
	// (void)context; // dont need it so we silence it
	if (signum == SIGUSR1)
		c |= 1 << bit_counter;
	bit_counter++;
	if (bit_counter == 8)
	{
		bit_counter = 0;
		write(1, &c, 1);
		c = 0;
	}
}
int	main(int argc, char **argv)
{
	struct sigaction sa;

	ft_printf("PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask); // initalize
	sa.sa_flags = SA_RESTART | SA_SIGINFO; // set flags or inialize???
	sa.sa_sigaction = sig_handler;
	while (1)
	{
		// recieve_bits(); // useless since apparently pause invokes the signal handler
		pause();
	}
	return (0);
}