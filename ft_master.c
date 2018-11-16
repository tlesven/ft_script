/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_master.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 22:09:53 by tlesven           #+#    #+#             */
/*   Updated: 2014/04/30 23:07:49 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_script.h"
#include <sys/select.h>
#include <unistd.h>

fd_set		init_fdset(int fd, fd_set fd_in)
{
	FD_ZERO(&fd_in);
	FD_SET(0, &fd_in);
	FD_SET(fd, &fd_in);
	return (fd_in);
}

void		ft_master_next(fd_set fd_in, int fdm, int fdf)
{
	int		ret;
	char	input[BUFF_SIZE];

	if (FD_ISSET(fdm, &fd_in))
	{
		ret = read(fdm, input, BUFF_SIZE);
		if (ret > 0)
		{
			write(1, input, ret);
			write(fdf, input, ret);
		}
		else if (ret == 0)
		{
			ft_message(2, fdf);
			_exit(0);
		}
	}
}

void		ft_master(int fdm, int fdf)
{
	fd_set		fd_in;
	int			ret;
	char		input[BUFF_SIZE];

	while (1)
	{
		fd_in = init_fdset(fdm, fd_in);
		ret = select(fdm + 1, &fd_in, NULL, NULL, NULL);
		if (FD_ISSET(0, &fd_in))
		{
			ret = read(0, input, BUFF_SIZE);
			if (ret > 0)
			{
				write(fdm, input, ret);
				write(fdf, input, ret);
			}
		}
		else if (ret < 0)
			return ;
		ft_master_next(fd_in, fdm, fdf);
	}
}
