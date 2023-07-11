/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:00:55 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/11 19:28:36 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(void)
{
	int	pid;

	pid = getpid();
	if (pid == -1)
	{
		ft_printf("Error, please try again\n");
		exit(1);
	}
	ft_printf("Server PID: %d\n", pid);
}

static void	msg_handler(int sig_no, siginfo_t *info, void *context)
{
	static unsigned char	ch;
	static int				bit;
	static unsigned char	message[4096];

	(void)context;
	if (sig_no == SIGUSR1)
		ch |= (1 << bit % 8);
	if (bit++ == 0)
		ft_printf("Message from client @%d: ", info->si_pid);
	if (bit % 8 == 0)
	{
		if (ch == '\0')
		{
			write(1, message, bit / 8);
			write(1, "\n", 1);
			ft_bzero(message, bit / 8);
			bit = 0;
			kill(info->si_pid, SIGUSR2);
		}
		else
		{
			message[bit / 8 - 1] = ch;
			ch = '\0';
		}
	}
}

int	main()
{
	struct sigaction		sa;

	print_pid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = msg_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
