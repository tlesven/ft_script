/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 20:25:05 by tlesven           #+#    #+#             */
/*   Updated: 2014/04/30 22:24:05 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_script.h"
#include "libft.h"

int			init_master(void)
{
	int		fd;

	if ((fd = ft_posix_openpt(O_RDWR)) < 0)
		return (-1);
	if (ft_grantpt(fd))
		return (-1);
	if (ft_unlockpt(fd))
		return (-1);
	return (fd);
}

void		ft_script(int fdf, char **env, char **av)
{
	int		fdm;
	int		fds;

	if ((fdm = init_master()) == -1)
		return ;
	fds = open(ft_ptsname(fdm), O_RDWR);
	ft_message(1, fdf);
	if (fork())
	{
		close(fds);
		ft_master(fdm, fdf);
	}
	else
	{
		close(fdm);
		ft_slave(fds, env, av);
		return ;
	}
}
