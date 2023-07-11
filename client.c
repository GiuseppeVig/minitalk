/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:01:09 by gvigilan          #+#    #+#             */
/*   Updated: 2023/06/13 16:01:09 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bytes(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

void	handle_response(int signum)
{
	if (signum == SIGUSR2)
	{
		ft_printf("Message Sent Successfully!");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("ERROR: Follow this format %s-PID-Message", argv[0]);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
	while (argv[2][i])
	{
		send_bytes(argv[2][i], pid);
		i++;
	}
}
