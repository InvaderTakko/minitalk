/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:16:10 by sruff             #+#    #+#             */
/*   Updated: 2024/05/07 15:48:13 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// static void free_and_reset(t_server *s)
// {
// 	free(s->str);
// 	s->str = NULL;
// 	s->bit_counter = 0;
// 	s->str_len = 0;
// 	s->pid = 0;
// 	s->c = 0;
// 	s->flag = 0;
// }

static	size_t	get_str_len(int signum, t_server *s)
{
	if (s->bit_counter < (8 * sizeof(size_t)))
	{
		if (signum == SIGUSR1)
		{
			s->str_len |= (size_t)1 << s->bit_counter;
		}
		s->bit_counter++;
		if (s->bit_counter == sizeof(size_t) * 8)
		{
			return (1);
		}
	}
	else
	{
		s->bit_counter++;
	}
	return (0);
}
// {


static	void 	bit_to_char(int sig, t_server *s)
{
	static int	bit;

	if (s->flag == 1)
	{
		s->flag = 0;
		s->c = 0;
	}
	if (sig == SIGUSR1)
		s->c = s->c | (1 << bit);
	if (sig == SIGUSR2)
		s->c = s->c | (0 << bit);
	bit++;
	if (bit == 8)
	{
		s->flag = 1;
		bit = 0;
	}
}

// test later if i need void *context
void sig_handler(int signum, siginfo_t *info, void *context)
{
	static t_server s = {0, NULL, 0, 0, 0, 0};
	
	(void)context; // dont need it so we silence it
	// ft_printf("do i get here\n");
	if (s.pid == 0)
		s.pid = info->si_pid;
	if (s.pid != info->si_pid)
	{
		kill(s.pid, SIGUSR2);
		ft_printf("Wrong PID\n");
		free(s.str);
		// s = (t_server){0, NULL, 0, 0, 0, 0};
		ft_memset(&s, 0, sizeof(t_server));
		exit(EXIT_FAILURE); // either exit or resets statics+free and let it run
	}
	if (get_str_len(signum, &s) == 1)
	{
		if (s.str_len == 0)
			exit(EXIT_SUCCESS); // maybe its a fail? ft_printf("Empty string\n")
		// ft_printf("String length: %i\n", str_len);	
		s.str = (char *)malloc(sizeof(char) * (s.str_len + 1));
		if (!s.str)
		{
			ft_printf("Malloc failed\n");
			exit(EXIT_FAILURE);
		}
		s.str[s.str_len] = '\0';
	}
	if  (s.bit_counter > sizeof(size_t) * 8)
	{
		bit_to_char(signum, &s);
		if( s.flag == 1)
		{
			// ft_printf("Char: %c\n", c);
			s.str[(s.bit_counter - sizeof(size_t) * 8) / 8 - 1] = s.c;
			// ft_printf("String: %s\n", str);
			// ft_printf("Bit counter: %i\n", bit_counter);
			// ft_printf("my calc %i\n", str_len * sizeof(char) * 8 + sizeof(size_t) * 8);
			if (s.bit_counter == s.str_len * sizeof(char) * 8 + sizeof(size_t) * 8)
			{
				ft_printf("String: %s\n", s.str);
				free(s.str);
				kill(s.pid, SIGUSR1);
				ft_memset(&s, 0, sizeof(t_server));
			}
		}
	}
}
int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	(void)argc;
	ft_printf("PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask); // initalize
	sa.sa_flags = SA_RESTART | SA_SIGINFO; // set flags or inialize???
	sa.sa_sigaction = sig_handler;
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("sigaction");
		return EXIT_FAILURE;
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction");
		return EXIT_FAILURE;
    }	
	while (1)
	{
		// recieve_bits(); // useless since apparently pause invokes the signal handler
		pause();
	}
	return (0);
}


	// once bitcounter == (str_len +1) * sizeof(size_t) * 8 we can print the string
	// send signal to client that we are done
	// and free the string

	// if (signum == SIGUSR1)
	// 	c |= 1 << bit_counter++;
	// else if (signum == SIGUSR2)
	// 	bit_counter++;