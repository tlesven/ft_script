/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slave.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 14:26:03 by tlesven           #+#    #+#             */
/*   Updated: 2014/04/30 21:47:52 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "ft_script.h"
#include "libft.h"

void		ft_exe_sh(char **env, char **av)
{
	char	*sh;
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "SHELL=", 6))
		{
			sh = env[i];
			break ;
		}
		i++;
	}
	execve(sh + 6, av, env);
}

void		ft_slave(int fds, char **env, char **av)
{
	int				ret;
	char			**tab;

	close(0);
	close(1);
	close(2);
	dup(fds);
	dup(fds);
	dup(fds);
	close(fds);
	setsid();
	ioctl(0, TIOCSCTTY, 1);
	ft_exe_sh(env, av);
	return ;
}
