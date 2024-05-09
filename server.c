/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:16:10 by sruff             #+#    #+#             */
/*   Updated: 2024/05/09 16:22:36 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	bit_to_char(int sig, t_server *s)
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
// ft_printf("my calc %i\n", str_len * sizeof(char) * 8 + sizeof(size_t) * 8);

static void	set_and_print_str(int sig, t_server *s)
{
	bit_to_char(sig, s);
	if (s->flag == 1)
	{
		s->str[(s->bit_counter - sizeof(size_t) * 8) / 8 - 1] = s->c;
		if (s->bit_counter == s->str_len * 8 + sizeof(size_t) * 8)
		{
			ft_printf("%s\n", s->str);
			free(s->str);
			kill(s->pid, SIGUSR1);
			ft_memset(s, 0, sizeof(t_server));
		}
	}
}

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

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static t_server	s = {0, NULL, 0, 0, 0, 0};

	(void)context;
	if (s.pid == 0)
		s.pid = info->si_pid;
	if (s.pid != info->si_pid)
	{
		kill(s.pid, SIGUSR2);
		ft_printf("Error: you are sending from 2 clients at once\n");
		free(s.str);
		ft_memset(&s, 0, sizeof(t_server));
		exit(EXIT_FAILURE);
	}
	if (get_str_len(signum, &s) == 1)
	{
		s.str = (char *)malloc(sizeof(char) * (s.str_len + 1));
		if (!s.str)
		{
			ft_printf("Malloc failed\n");
			exit(EXIT_FAILURE);
		}
		s.str[s.str_len] = '\0';
	}
	if (s.bit_counter > sizeof(size_t) * 8)
		set_and_print_str(signum, &s);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	(void)argc;
	ft_printf("PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (EXIT_FAILURE);
	while (1)
	{
		pause();
	}
	return (0);
}

// once bitcounter == (str_len +1) * sizeof(size_t) * 8 
//we can print the string
