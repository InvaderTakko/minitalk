/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:16:10 by sruff             #+#    #+#             */
/*   Updated: 2024/04/24 18:50:56 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static size_t get_str_len(int signum, size_t *str_len, size_t *bit_counter)
{

	if (*bit_counter < sizeof(size_t))
	{
		if (signum == SIGUSR1)
		{
			*str_len |= (size_t)1 << *bit_counter++;
			if (*bit_counter == sizeof(size_t) * 8)
			{

				return (1);
			}
		}
	}
	else
		*bit_counter++;
	return (0);
}

static void  bit_to_char(int sig, char *c, int flag)
{
	static int	bit;
	
	if (sig == SIGUSR1)
		*c = *c | (1 << bit);
	if (sig == SIGUSR2)
		*c = *c | (0 << bit);
	bit++;
	if (bit == 8)
	{	
		if (flag == 1)
		{
			bit = 0;
			*c = 0;
		}
	}
}

// test later if i need void *context
void sig_handler(int signum, siginfo_t *info, void *context)
{
	static size_t bit_counter;
	static char *str;
	static char *c;
	static size_t str_len;
	static int flag;
	static int pid;

	(void)context; // dont need it so we silence it
	if (pid == 0)
		pid = info->si_pid;
	if (get_str_len(signum, &str_len, &bit_counter) == 1)
	{
		if (str_len == 0)
			exit(EXIT_SUCCESS); // maybe its a fail? ft_printf("Empty string\n")
		str = (char *)malloc(sizeof(char) * str_len + 1);
		if (!str)
		{
			ft_printf("Malloc failed\n");
			exit(EXIT_FAILURE);
		}
		str[str_len] = '\0';
	}
	else if  (bit_counter > sizeof(size_t) * 8)
	{	
		bit_to_char(signum, c, flag);
		if(bit_counter % 8 == 0)
		{
			str[bit_counter - sizeof(size_t) * 8] = *c;
			flag = 1;
			
		}
	}
	// once bitcounter == (str_len +1) * sizeof(size_t) * 8 we can print the string
	// send signal to client that we are done
	// and free the string

	// if (signum == SIGUSR1)
	// 	c |= 1 << bit_counter++;
	// else if (signum == SIGUSR2)
	// 	bit_counter++;
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