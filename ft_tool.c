/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 18:58:16 by tlesven           #+#    #+#             */
/*   Updated: 2014/05/01 11:22:07 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/time.h>
#include "libft.h"
#include "ft_script.h"

char	*singleton_file(char *s)
{
	static char *file = NULL;

	if (s)
		file = s;
	return (file);
}

char	*ft_date(void)
{
	char			*str;
	struct timeval	tp;
	struct timezone	tzp;

	gettimeofday(&tp, &tzp);
	settimeofday(&tp, &tzp);
	str = ctime(&tp.tv_sec);
	return (str);
}
