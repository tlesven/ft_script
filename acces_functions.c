/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acces_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 17:00:36 by tlesven           #+#    #+#             */
/*   Updated: 2014/04/29 18:01:09 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_script.h"

int		ft_posix_openpt(int flags)
{
	int fd;

	if ((fd = open("/dev/ptmx", flags)) >= 0)
		return (fd);
	return (-1);
}

int		ft_grantpt(int fd)
{
	return (ioctl(fd, TIOCPTYGRANT));
}

char	*ft_ptsname(int fd)
{
	static char			ptsnamebuff[128];
	struct stat			sbuf;

	if (!ioctl(fd, TIOCPTYGNAME, ptsnamebuff))
	{
		if (stat(ptsnamebuff, &sbuf) == 0)
			return (ptsnamebuff);
	}
	return (NULL);
}

int		ft_unlockpt(int fd)
{
	return (ioctl(fd, TIOCPTYUNLK));
}
