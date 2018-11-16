/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 19:16:58 by tlesven           #+#    #+#             */
/*   Updated: 2014/05/01 11:20:35 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_script.h"
#include "libft.h"

int		ft_quiet(int i)
{
	static int		quiet = 0;

	if (i != 0)
		quiet = i;
	return (quiet);
}

int		ft_open_file(int flag, char *file)
{
	if (!file)
		file = "typescript";
	singleton_file(file);
	if (flag == 2 || flag == 3)
		ft_quiet(1);
	if (flag == 1 || flag == 3)
		return (open(file, O_CREAT | O_APPEND | O_RDWR, 0777));
	else
		return (open(file, O_CREAT | O_RDWR, 0777));
}

int		ft_flag(int argc, char **argv)
{
	int		i;
	int		j;
	int		flag;

	i = 1;
	flag = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			j = 1;
			while (argv[i][j])
			{
				if (argv[i][j] == 'a' && flag != 1 && flag != 3)
					flag += 1;
				if (argv[i][j] == 'q' && flag != 2 && flag != 3)
					flag += 2;
				j++;
			}
			i++;
		}
		else
			break ;
	}
	return (ft_open_file(flag, argv[i]));
}

void	ft_message(int i, int fdf)
{
	if (i == 1)
	{
		if (!ft_quiet(0))
		{
			ft_putstr("Script started, output file is ");
			ft_putendl(singleton_file(NULL));
		}
		ft_putstr_fd("Script started on ", fdf);
		ft_putendl_fd(ft_date(), fdf);
	}
	if (i == 2)
	{
		if (!ft_quiet(0))
		{
			ft_putstr("Script done, output file is ");
			ft_putendl(singleton_file(NULL));
		}
		ft_putstr_fd("Script done on ", fdf);
		ft_putendl_fd(ft_date(), fdf);
	}
	fdf = fdf;
}

int		main(int argc, char **argv, char **env)
{
	int		fdf;

	fdf = ft_flag(argc, argv);
	if (argc >= 2)
		argv[1] = NULL;
	ft_script(fdf, env, argv);
	ft_message(2, fdf);
	return (0);
}
